private ["_plane"];
_plane = _this select 0;

If (!Local _Plane) ExitWith {};


waitUntil {
	_magazines = magazines _Plane;
	_CMag = currentMagazine _plane;
	_CWeap =  currentWeapon _plane;
	If (isEngineOn _plane and ({_x == "2Rnd_PAKFA_empty"} count _magazines) < 2) then {
		if ((_CWeap == "Missile_AA_01_PAKFA_F" and _CMag == "2Rnd_Missile_AA_RVVSD_F" and _CMag in _magazines)	or
		(_CWeap == "Missile_Ch38_PAKFA_F" and _CMag == "2Rnd_Missile_Ch38_PAKFA_F" and _CMag in _magazines) or
		(_CWeap == "Bomb_KAB250_PAKFA_F" and _CMag == "2Rnd_Bomb_KAB250_F" and _CMag in _magazines)) then {
			if (_plane animationPhase "weapon_hatch_1_1" != 1) THEN {
				_plane animate ["weapon_hatch_1_1",1];
				_plane animate ["weapon_hatch_1_2",1];
				_plane animate ["weapon_hatch_2_2",1];
				_plane animate ["weapon_hatch_2_1",1];
				_plane animate ["display1_Bays_unhide",1];
			};
		} else {
			if (_plane animationPhase "weapon_hatch_1_1" != 0) THEN {
			sleep 0.3;
			_plane animate ["weapon_hatch_1_1",0];
			_plane animate ["weapon_hatch_1_2",0];
			_plane animate ["weapon_hatch_2_2",0];
			_plane animate ["weapon_hatch_2_1",0];
			_plane animate ["display1_Bays_unhide",0];
			};
		};
	};
	sleep 0.01;
	!(ALIVE _plane)
};

/*
Mags = magazines vehicle player; CntMags = {_x == "2Rnd_Missile_AA_RVVSD_F"} count Mags; hint format ["Magazines: %1; Count Ch-38: %2", mags, CntMags];
*/