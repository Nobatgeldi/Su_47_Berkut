// // // // // // // // // //
// Interior Light script
// Version 1.653
// Date: 2015.03.14
// Authors: Lala14, Tajin
// // // // // // // // // //

// init line:
// nul=[] execVM "IntLight.sqf";

/*Definable*/
if (isNil {IL_Debug}) then {
IL_Debug = false; 			//Enable Debug Mode
};
if (isNil {IL_Balls}) then {
IL_Balls = false; 			//Show the attach points (requires Debug mode)
};
if (isNil {IL_Crew_Only}) then {
IL_Crew_Only = true; 		//Only allow Pilot/Driver/Co-Pilot/Gunner/Commander (does not include left & right gunners for choppers) to change the light
};
if (isNil {IL_Red_On_Always}) then {
IL_Red_On_Always = true; 	//When true, when light is turned off then on the light will be reset to red else it will never be reset if false
};
if (isNil {IL_Action_Night}) then {
IL_Action_Night = false; 	//Only allow the action to come up during the Dark times
};
/*End Definable*/
/*Start Script*/
IL_Loaded = false;

if (isDedicated) exitWith {};

waitUntil {!isNull player};

systemChat "Interior Lighting: Loading";

diag_log "IL starting";


// light colors:
IL_c_white = [255,255,255];
IL_c_red = [255,0,0];
IL_c_green = [0,255,0];
IL_c_blue = [0,0,255];
IL_c_yellow = [255,200,0];
IL_c_orange = [255,75,0];

// predefined default values used in the config below
IL_attenuation = [0.3,0,0,500];
IL_att_soft = [0,10,10,10];
IL_att_tiny = [0,0,0,0,0.2,0.4];
IL_intensity = 50;

// To make all lights brighter or darker, simply adjust the following multiplier.
IL_intensity_mult = 0.5;

diag_log "IL config loading";

/*config
	["kindOf classnames", "First person only",[
		["position in modelspace","lightcolor","attentuation","intensity"]
	],"Allow Colour Change",(optional - if not present but there is 2 it will change it) which lights to be able to change to green *first to number* ]*/

if (isNil "IL_config") then
{
    IL_config = [];
};
IL_config = IL_config + [
[["Su_47_Berkut"], false, [
		 [ [0,3.8,-0.4], IL_c_green, IL_attenuation, IL_intensity ]
	],false]
];
// The config-array can be modified at runtime. This also allows modautors to append their own settings without having to edit this script.


diag_log "IL config done";

// vars
if (isNil {IL_typelist}) then { IL_typelist = []; };
if (isNil {IL_lights}) then { IL_lights = []; };
if (isNil {IL_varname}) then { IL_varname = "interiorlight"; };
if (isNil {IL_text_ON}) then { IL_text_ON = "<t color='#FF0000'>Turn Interior Light ON</t>"; };
if (isNil {IL_text_OFF}) then { IL_text_OFF = "<t color='#FF0000'>Turn Interior Light OFF</t>"; };
if (isNil {IL_Green_Text}) then { IL_Green_Text = "<t color='#00FF00'>Change Light to Green</t>"; };
if (isNil {IL_Red_Text}) then { IL_Red_Text = "<t color='#FF0000'>Change Light to Red</t>"; };
if (isNil {IL_action}) then { IL_action = -1; };
if (isNil {IL_action2}) then { IL_action2 = -1; };
if (isNil {IL_eventHandler}) then { IL_eventHandler = -1; };
if (isNil {IL_lastchange}) then { IL_lastchange = 0; };

// functions
IL_fnc_inList = {
	_found = false;
	_index = -1;
	{
		_types = _x select 0;
		{
			if (_this isKindOf _x) exitWith { _found = true; };
		} forEach _types;
		if _found exitWith {_index = _forEachIndex;};
	} forEach IL_config;
	_index
};

IL_fnc_returnTurretUnits = {
	_peeps = [];
	_turrets = allTurrets [_this,false];
	{
		if (!isNull (_this turretUnit _x)) then {_peeps pushBack (_this turretUnit _x)};
	}forEach _turrets;
	_peeps;
};

IL_fnc_attachTo = {
	_light = _this select 0;
	_veh = _this select 1;
	_pos = _this select 2;
	waitUntil
	{
	 _light setPos (_veh modelToWorld _pos); isNull _light
	 };
};

IL_fnc_addAction = {
	if (IL_action > -1) then {
		player removeAction IL_action;
		if (IL_Debug) then {player sideChat 'action removed'};
	};

	IL_action = player addAction [
	IL_text_ON,
	"
		_veh = vehicle player;
		_ison = _veh getVariable [IL_varname,false];
		if (_ison) then {
			_veh setVariable[IL_varname,false,true];
		} else {
			_veh setVariable[IL_varname,true,true];
		};
		if (IL_Debug) then {player sideChat format ['vehicle was chosen because of this classname %1', IL_config select (_veh call IL_fnc_inList) select 0]};
	",
	"",
	0.999,
	false,
	false,
	"",
	"
		_veh = vehicle player;
		_show = false;
		if ( (_veh != player) ) then {
			_vehtype = typeOf _veh;
			_i = _veh call IL_fnc_inList;
			if (_i > -1) then {
				_show = true;
				_ison = _veh getVariable [IL_varname,false];
				if (_ison) then {
					player setUserActionText[IL_action,IL_text_OFF];

					if ( (cameraView != 'INTERNAL') && ((IL_config select _i) select 1) ) then {
						if (count IL_lights > 0) then {
							if (IL_Debug) then {player sideChat 'Lights being removed because in third person'};
							if ((IL_Debug) && (IL_Balls) && !(isNil {_veh getVariable 'il_balls'})) then {
								{
									deleteVehicle _x;
								} forEach (_veh getVariable 'il_balls');
								_veh setVariable ['il_balls',nil,true];
								if (IL_Debug) then {player sideChat format ['Balls being removed because in third person %1',str IL_lights];};
							};
							{
								IL_lights = IL_lights - [_x];
								deleteVehicle _x;
							} forEach IL_lights;
						};
					} else {
						_lights = (IL_config select _i) select 2;
						_timestamp = _veh getVariable ['IL_timestamp',IL_lastchange];

						if (count IL_lights == 0) then {
							if (IL_Debug) then {player sideChat 'lights added, hint displayed for the array'; hintSilent str _lights;};
							{
								_light = '#lightpoint' createVehicleLocal [0,0,0];
								_light attachTo [_veh,(_x select 0)];
								_light setLightColor (_x select 1);
								_light setLightAttenuation (_x select 2);
								_light setLightIntensity (_x select 3) * IL_intensity_mult;
								if (IL_Debug && IL_Balls) then {
									if (isNil {_veh getVariable 'il_balls'}) then {
										_ball = 'Sign_Sphere10cm_F' createVehicle [0,0,0];
										_ball attachTo [_light,[0,0,0]];
										_veh setVariable ['il_balls',[_ball],true];
									} else {
										_ball = 'Sign_Sphere10cm_F' createVehicle [0,0,0];
										_ball attachTo [_veh,(_x select 0)];
										_veh setVariable ['il_balls',(_veh getVariable 'il_balls') + [_ball],true];
									};
								};
								IL_lights pushBack _light;
								IL_lastchange = 0;
							} forEach _lights;
						};

						if (_timestamp != IL_lastchange) then {
							_override = _veh getVariable ['IL_override',_lights];
							if (IL_Debug) then {player sideChat format ['light colour changed',str _override];};
							{
								_o = _override select _forEachIndex;
								_x attachTo [_veh,(_o select 0)];
								_x setLightColor (_o select 1);
								_x setLightAttenuation (_o select 2);
								_x setLightIntensity (_o select 3) * IL_intensity_mult;
							} forEach IL_lights;
							IL_lastchange = _timestamp;
						};
					};
				} else {
					if (IL_Red_On_Always) then { _veh setVariable ['IL_override',nil,true]; };
					player setUserActionText[IL_action,IL_text_ON];
					if (count IL_lights > 0) then {
						if (IL_Debug) then {player sideChat format ['removing lights because lights are off %1',str IL_lights];};
						{
							IL_lights = IL_lights - [_x];
							deleteVehicle _x;
						} forEach IL_lights;
						if ((IL_Debug) && (IL_Balls) && !(isNil {_veh getVariable 'il_balls'})) then {
							{
								deleteVehicle _x;
							} forEach (_veh getVariable 'il_balls');
							_veh setVariable ['il_balls',nil,true];
							if (IL_Debug) then {player sideChat format ['removing balls because lights are off %1',str IL_lights];};
						};
					};
				};
			};
		} else {
			if (count IL_lights > 0) then {
				if (IL_Debug) then {player sideChat format ['removing lights because you are not in a vehicle %1',str IL_lights];};
				{
					IL_lights = IL_lights - [_x];
					deleteVehicle _x;
				} forEach IL_lights;
			};
		};
		if (IL_Crew_Only) then { _show = (_show && ((_this == driver _target) OR (_this == gunner _target) OR (_this == commander _target) OR (_this in (vehicle _target call IL_fnc_returnTurretUnits)))) };
		if (IL_Action_Night && sunOrMoon == 1) then { _show = (_show && (vehicle _target getVariable [IL_varname,false] )) };
		_show
	"];
	if (IL_Debug) then {player sideChat 'action added'};

	if (IL_action2 > -1) then {
		player removeAction IL_action2;
		if (IL_Debug) then {player sideChat 'action2 removed'};
	};

	IL_action2 = player addAction [
	IL_Green_Text,
	"
		_veh = vehicle player;
		_i = _veh call IL_fnc_inList;
		_lights = + (IL_config select _i) select 2;
		_lighter = _lights select 0;
		_lightamount = (IL_config select _i) select 4;

		if (isNil {_veh getVariable 'IL_override'}) then {
			_lighter set [1,IL_c_green];

			if (count _lights > 1 && isNil {_lightamount}) then {
				_lighters = _lights select 1;
				_lighters set [1,IL_c_green];
				_lights set [1,_lighters];
			};

			if (!isNil {_lightamount}) then {
				{
				_x set [1,IL_c_green];
				_lights set [_forEachIndex,_x];
				}forEach _lights;
			};

			_lights set [0,_lighter];
			_veh setVariable ['IL_override',_lights,true];
			_veh setVariable ['IL_timestamp',time,true];
		} else {
			_veh setVariable ['IL_override',nil,true];
			_veh setVariable ['IL_timestamp',time,true];
		};
	",
	"",
	0.99,
	false,
	false,
	"",
	"
		_veh = vehicle player;
		_i = _veh call IL_fnc_inList;
		_show = false;
		if (!(isNil {_veh getVariable 'IL_override'}) && (IL_c_green in ((_veh getVariable 'IL_override') select 0))) then { player setUserActionText[IL_action2,IL_Red_Text];};
		if (isNil {_veh getVariable 'IL_override'}) then { player setUserActionText[IL_action2,IL_Green_Text];};
		if ((_veh != player) && (_i > -1)) then { _show = ((_i > -1) && ((IL_config select _i) select 3)) };
		if (IL_Crew_Only) then { _show = (_show && ((_this == driver _target) OR (_this == gunner _target) OR (_this == commander _target) OR (_this in (vehicle _target call IL_fnc_returnTurretUnits)))) };
		_veh getVariable [IL_varname,false] &&
		_show
	"];
	if (IL_Debug) then {player sideChat 'action2 added'};
	if (IL_Debug && IL_Crew_Only) then {player sideChat "IL_Crew_Only Active"};
	if (IL_Debug && IL_Red_On_Always) then {player sideChat "IL_Red_On_Always Active"};
};

diag_log "IL func loaded";

// init
if (IL_eventHandler > -1) then {
	player removeEventHandler ["Respawn",IL_eventHandler];
	if (IL_Debug) then {player sideChat "IL Respawn EventHandler Removed"};
};

[] spawn IL_fnc_addAction;
IL_eventHandler = player addEventHandler ["Respawn", {
	[] spawn IL_fnc_addAction;
	if (IL_Debug) then {player sideChat "IL Respawn EventHandler Executed!";};
}];
if (IL_Debug) then {player sideChat format ["IL Respawn EventHandler Added, #%1",IL_eventHandler];};

IL_Loaded = true;
diag_log "IL ready";
systemChat "Interior Lighting: Initialized";