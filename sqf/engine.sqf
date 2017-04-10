/*
	author: Nobat
	description: none
	returns: nothing
*/

private ["_plane","_engine","_array","_r73_ammo_count","_ammo_count","_count_help"];

_array  = _this select 0;
_plane  = _array select 0;
_engine = _array select 1;

_count_help = 2;

 if (_engine) then
 {
    _plane animateSource  ["LCD_control",0];
    // missile  select LCD
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
 }
 else
 {
    _plane animateSource  ["LCD_control",1];
    // missile  select LCD
    _plane animateSource  ["R_73_m1",1];
    _plane animateSource  ["R_73_m2",1];
    _plane animateSource  ["R_73_m3",1];
    _plane animateSource  ["R_73_m4",1];
 };