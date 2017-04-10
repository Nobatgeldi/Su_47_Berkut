/*
	author: Nobat
	description: none
	returns: nothing
*/

private ["_plane","_array","_gear"];

_array  = _this select 0;
_plane  = _array select 0;
_gear   = _array select 1;

 if (_gear) then
 {
       //show flaps text in LCD
       _plane setObjectTexture [5, "\Su_47_Berkut\tex\LCD\plane_gear.paa"];

 }
 else
 {
       //hide flaps text in LCD
       _plane setObjectTexture [5, "\Su_47_Berkut\tex\LCD\plane.paa"];
 };