
///-------------------<>----------------///
///     Author: Nobat                   ///
///       Date: 20 July                 ///
///    Project: VMT                     ///
///       File: serial_COM.sqf          ///
/// Permission: GPL v3.0                ///
///-------------------<>----------------///


private ["_plane","_x_axis","_y_axis","_z_axis"];

_plane = _this;
//_names = animationNames _plane;
while {(alive _plane)} do
{
                                        //_y_axis = _plane animationSourcePhase "horizonDive";
    //get radian numbers for x and z axis
    _x_axis = _plane animationPhase  "horizonDive";
    _z_axis = _plane animationPhase  "horizonBank";
    _y_axis = getDir _plane;
    sleep 0.001;
};