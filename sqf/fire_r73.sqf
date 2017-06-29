/*
	author: Nobat
	description: none
	returns: nothing
*/
private ["_plane","_r73_ammo_count","_magazine_count","_count_help"];

_plane = _this;

if ("Su_300Rnd_30mm_GSh301" in (magazines _plane)) then
{
 _count_help = 2;
}
else
{
 _count_help = 1;
};
//_r73_ammo_count = count _magazines_select;
if(isEngineOn _plane) then
{
   // missile  select LCD
   _magazine_count = count magazines _plane;
   _r73_ammo_count = _magazine_count-_count_help;
    switch(_r73_ammo_count) do
    {
        case 1:
        {
           _plane animateSource  ["R_73_m1",1];
           _plane animateSource  ["R_73_m2",1];
           _plane animateSource  ["R_73_m3",1];
           //_plane animateSource  ["R_73_m4",0];
        };
        case 2:
        {
           _plane animateSource  ["R_73_m1",1];
           _plane animateSource  ["R_73_m2",1];
           /*_plane animateSource  ["R_73_m3",0];
           _plane animateSource  ["R_73_m4",0];*/
        };
        case 3:
        {
           _plane animateSource  ["R_73_m1",1];
           /*_plane animateSource  ["R_73_m2",0];
           _plane animateSource  ["R_73_m3",0];
           _plane animateSource  ["R_73_m4",0];*/
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
       _plane animateSource  ["R_73_m1",1];
       _plane animateSource  ["R_73_m2",1];
       _plane animateSource  ["R_73_m3",1];
       _plane animateSource  ["R_73_m4",1];
};
