/*
	author: Nobat
	description: none
	returns: nothing
*/

private ["_plane","_weapon","_script"];

_plane  = _this select 0;
_weapon = _this select 1;
_script = [];

if(_weapon == "Su47_R73M1Launcher") then
{
	_script set [0, _plane execVM "\Su_47_Berkut\sqf\fire_r73.sqf"];
}
else
{
    _script set [0, _plane execVM "\Su_47_Berkut\sqf\Gsh.sqf"];
    //, _plane call BIS_Effects_EH_Fired
};