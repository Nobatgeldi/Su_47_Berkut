class CfgAmmo
{
	class MissileBase;
	class Cannon_30mm_HE_Plane_CAS_02_F;
	class B_30mm_MP_Tracer_Red;
	class Bomb_04_F;
	class LaserBombCore;
	class BombCore;

	class Su47_fak_ammo: MissileBase
	{
		model="\Mikoyan-Mig-29\wep\fake_w.p3d";
		proxyShape="\Mikoyan-Mig-29\wep\fake_w.p3d";
	};

	// short range
	class Su47_R73_AA: MissileBase
	{
		model="\Mikoyan-Mig-29\wep\R73_proxy.p3d";
		proxyShape="\Mikoyan-Mig-29\wep\R73_proxy.p3d";
		hit=200;
		weaponType = "missileAA"; //Overrides the engine determination of weapon type
															//based on ammo simulation, for vehicle weapon grouping.
		guidanceInitTime=1; //Defines how long a projectile waits before starting its engine.
		trackOversteer=2;   //Defines how a missile over steers.	1 - no oversteer
										    //Values higher than 1 result in more over steer.
		indirectHit=85;
		indirectHitRange=10;
		maneuvrability=27;
		cmImmunity=0.70;
		simulation="shotMissile";
		simulationStep=0.0020000001;
		airLock=2;
		irLock=1;
		laserLock = true;
		laserScanRange = 10000;
		cost=1500;
		maxSpeed=828; //Meters per second  Defines the maximum speed of ammunition (missiles and rockets).
		timeToLive=40;
		airFriction=0.050000001;
		sideAirFriction=0.1;
		trackLead=1;
		initTime=1;
		thrustTime=20;
		thrust=240;
		fuseDistance=500; //Defines the distance traveled before ammunition is fused.
		CraterEffects="AAMissileCrater";
		explosionEffects="AAMissileExplosion";
		whistleDist=20;
		muzzleEffect="BIS_fnc_effectFiredHeliRocket";

		weaponLockSystem="2 + 8 + 4"; //	Defines the type of detection system
																	 // that can detect this munition when it is locked on to a target.
																	 // GUIDANCE_NONE 0 GUIDANCE_VISUAL 1
																	 // GUIDANCE_INFRARED 2 GUIDANCE_LASER 4
																	 // GUIDANCE_RADAR 8 DETECTION_MISSILE 16
		missileLockCone=120;
		maxControlRange=8000;
		class LaunchModes
		{
			class LOBL
			{
				launchAngle=40;
				targetingMode="LOBL";
				targetDistanceOverride=300;
			};
		};
	};
	class Su47_R73M1_AA: Su47_R73_AA
	{
		hit=350;
		indirectHit=100;
		initTime=0.8;
		indirectHitRange=20;
		maneuvrability=35;
	};
	class Su47_R60_AA: Su47_R73_AA
	{
		model="\Su_47_Berkut\wep\R_60.p3d";
		proxyShape="\Su_47_Berkut\wep\R_60.p3d";
		hit=350;
		indirectHit=100;
		initTime=0.8;
		indirectHitRange=20;
		maneuvrability=35;
	};
};
