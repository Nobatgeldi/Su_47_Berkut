/*
	author: Nobat
	description: none
	returns: nothing
*/

private ["_plane","_r73_ammo_count","_ammo_count","_script1","_count_help"];

_plane = _this select 0;
_script1 = [];
	_script1 set [0, _plane execVM "\Su_47_Berkut\sqf\FX_Afterburner.sqf"];
//_r73_ammo_count = count _magazines_select;

_count_help = 2;

waitUntil
		{
		    if(isEngineOn _plane) then
		    {
               _plane animateSource  ["LCD_control",0];
               // missile  select LCD
               _ammo_count = count magazines _plane;
               _r73_ammo_count = _ammo_count-_count_help;
                switch(_r73_ammo_count) do
                {
                    case 1:
                    {
                       _plane animateSource  ["R_73_m1",1];
                       _plane animateSource  ["R_73_m2",1];
                       _plane animateSource  ["R_73_m3",1];
                       _plane animateSource  ["R_73_m4",0];
                    };
                    case 2:
                    {
                       _plane animateSource  ["R_73_m1",1];
                       _plane animateSource  ["R_73_m2",1];
                       _plane animateSource  ["R_73_m3",0];
                       _plane animateSource  ["R_73_m4",0];
                    };
                    case 3:
                    {
                       _plane animateSource  ["R_73_m1",1];
                       _plane animateSource  ["R_73_m2",0];
                       _plane animateSource  ["R_73_m3",0];
                       _plane animateSource  ["R_73_m4",0];
                    };
                    case 4:
                    {
                       _plane animateSource  ["R_73_m1",0];
                       _plane animateSource  ["R_73_m2",0];
                       _plane animateSource  ["R_73_m3",0];
                       _plane animateSource  ["R_73_m4",0];
                    };
                    default
                    {
                       _plane animateSource  ["R_73_m1",1];
                       _plane animateSource  ["R_73_m2",1];
                       _plane animateSource  ["R_73_m3",1];
                       _plane animateSource  ["R_73_m4",1];
                    };

                };
                if (((_plane animationPhase "F_door") > 0.9)) then
                {
                        //show gear text in LCD
                }
                else
                {
                        //hide gear text in LCD
                };
                if (((_plane animationPhase "Flap_r") > 0.3) and ((_plane animationPhase "Flap_r") < 0.6)) then
                {
                  //show flaps text in LCD
                  _plane setObjectTexture [5, "\Su_47_Berkut\tex\LCD\plane_flaps.paa"];

                }
                if (((_plane animationPhase "Flap_r") == 1) ) then
                {
                  //show flaps text in LCD
                  _plane setObjectTexture [5, "\Su_47_Berkut\tex\LCD\plane_flaps_2.paa"];

                }
                else
                {
                  //hide flaps text in LCD
                  _plane setObjectTexture [5, "\Su_47_Berkut\tex\LCD\plane.paa"];
                };
		    }
            else
            {
                   _plane animateSource  ["LCD_control",1];
                    // missile  hide
                   _plane animateSource  ["R_73_m1",1];
                   _plane animateSource  ["R_73_m2",1];
                   _plane animateSource  ["R_73_m3",1];
                   _plane animateSource  ["R_73_m4",1];
            };

			if (currentWeapon _plane == "Su47_R73M1Launcher" and "Su47_R73M1" in (magazines _plane)) then
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
			if ("Mig_150Rnd_30mm_GSh301" in (magazines _plane)) then
			{
					_magazine_count = magazinesAmmo _plane;
					_gsh_301 = _magazine_count select 0;
					_ammo_count = _gsh_301 select 1;
					_animation_count = 150-_ammo_count;
          _plane animateSource  ["gsh_301_count",_animation_count];
			}
            else
			{
				_count_help = 1;
          //_plane animateSource  ["gsh_301_count",1];
			};
			sleep 0.005;
			!(alive _plane);
		};

exit;
