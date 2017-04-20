/*
	author: Nobat
	description: none
	returns: nothing
*/

private ["_plane","_script1"];

_plane = _this select 0;
_plane setObjectTexture [5, "\Su_47_Berkut\tex\LCD\plane_gear.paa"];
_script1 = [];
	_script1 set [0, _plane execVM "\Su_47_Berkut\sqf\FX_Afterburner.sqf"];
//_r73_ammo_count = count _magazines_select;

while {(alive _plane)} do
{
    if(isEngineOn _plane) then
    {
        if (currentWeapon _plane == "Su47_R73M1Launcher") then
        {
                _plane animateSource  ["missile",0];
                _plane setObjectTexture [0, "\Su_47_Berkut\tex\LCD\fire_s.paa"];
                _plane setObjectTexture [1, "\Su_47_Berkut\tex\LCD\fire_s.paa"];
                _plane setObjectTexture [2, "\Su_47_Berkut\tex\LCD\fire_s.paa"];
                _plane setObjectTexture [3, "\Su_47_Berkut\tex\LCD\fire_s.paa"];
        }
        else
        {
                _plane animateSource  ["missile",1];
                _plane setObjectTexture [0, "\Su_47_Berkut\tex\LCD\fire.paa"];
                _plane setObjectTexture [1, "\Su_47_Berkut\tex\LCD\fire.paa"];
                _plane setObjectTexture [2, "\Su_47_Berkut\tex\LCD\fire.paa"];
                _plane setObjectTexture [3, "\Su_47_Berkut\tex\LCD\fire.paa"];
        };
				if (currentWeapon _plane == "Su47_R60Launcher") then
        {
                _plane animateSource  ["missile_F",0];
        }
        else
        {
                _plane animateSource  ["missile_F",1];
        };
    };

    sleep 0.005;
};

exit;
