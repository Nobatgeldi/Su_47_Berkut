// -----------------------------
// configured for mig-29 by Gabby_NG
// -----------------------------
private ["_plane","_gunmodelpos","_vel","_gsh_301","_magazine_count","_ammo_count","_animation_count"];

_plane = _this select 0;
//_ammoname = _array select 4;
//_plane2 = _plane select 0;

//main

    _magazine_count = magazinesAmmo _plane;
    _gsh_301 = _magazine_count select 0;
    _ammo_count = _gsh_301 select 1;
    _animation_count = 150-_ammo_count;
    _plane animateSource  ["gsh_301_count",_animation_count];

	_gunmodelpos = _plane selectionPosition  "machine_gun";
	_vel = speed _plane;
	if(_vel > 40) then
	{
		drop [["\a3\data_f\ParticleEffects\Universal\Universal",16,1,16],	"", "Billboard", 0.3,0.01,_gunmodelpos,[5-random 20,5-random 20,5-random 20],1,1.275,1,0,[2.0, 2.0],[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]],[32], 0.01, 0.01, "", "", _plane];
		drop [["\a3\data_f\ParticleEffects\Universal\Universal", 16, 8, 16],"", "Billboard", 0.5, 0.07,_gunmodelpos,[5-random 20,5-random 20,5-random 20],1,1.275,1,0,[3,4+((3.3+random 4) /3)],[[0.6,0.6,0.6,0.2],[0.7,0.7,0.7,0.5],[0.7,0.7,0.7,0.35],[0.9,0.9,0.9,0.18], [1,1,1,0]],[8 + random 8],0.01,0.01,"","", _plane];
		sleep 0.005;
		drop [["\a3\data_f\ParticleEffects\Universal\Universal", 16, 8, 16],"", "Billboard", 0.5, 0.07,_gunmodelpos,[5-random 20,5-random 20,5-random 20],1,1.275,1,0,[4,4+((3.3+random 4) /3)],[[0.6,0.6,0.6,0.25],[0.7,0.7,0.7,0.4],[0.7,0.7,0.7,0.3],[0.9,0.9,0.9,0.18], [1,1,1,0]],[8 + random 8],0.01,0.01,"","", _plane];
	}
	else
	{
		drop [["\a3\data_f\ParticleEffects\Universal\Universal",16,0,32],	"", "Billboard", 0.3,0.05,_gunmodelpos,velocity _plane,1,1.275,1,0,[2.0, 2.0],[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]],[3 + random 2], 0.01, 0.01, "", "", _plane];
		drop [["\a3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48],"", "Billboard", 0.5, 0.3,_gunmodelpos,velocity _plane,1,1.275,1,0,[3,6+((3.3+random 5) /3)],[[0.6,0.6,0.6,0.2],[0.7,0.7,0.7,0.7],[0.7,0.7,0.7,0.65],[0.8,0.8,0.8,0.35],[0.9,0.9,0.9,0.18], [1,1,1,0]],[3 + random 2],0.01,0.01,"","", _plane];
	}
