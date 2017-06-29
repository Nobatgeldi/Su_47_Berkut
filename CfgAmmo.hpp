class CfgAmmo
{
	class Su_R73M1_AA;
	class Cannon_30mm_HE_Plane_CAS_02_F;
	class B_30mm_MP_Tracer_Red;
	class Bomb_04_F;
	class LaserBombCore;
	class BombCore;

	class Su47_fak_ammo: Su_R73M1_AA
	{
		model="";
		proxyShape="";
	};

	// short range
	class Su47_R73M1_AA: Su_R73M1_AA
	{
		hit=350;
		indirectHit=100;
		initTime=0.8;
		indirectHitRange=20;
		maneuvrability=35;
	};
	class Su47_R60_AA: Su_R73M1_AA
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
