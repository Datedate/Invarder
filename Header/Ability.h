#pragma once

namespace Ability {

	// 体力
	class HitPoint
	{
	public:
		HitPoint() {};
		HitPoint(int _hp) :val(_hp) {};
		~HitPoint() {};
	public:
		bool Damage(int _damage) {
			val -= _damage;
			if (val >= 0) return false;
			return true;
		}
		void Recovery(int _recovery) {
			val += _recovery;
		}
	private:
		int val;
	};

	// スピード
	class SPeed
	{
	public:
		SPeed() {};
		SPeed(float _spd) :val(_spd) {};
		SPeed(float _spd,float _min,float _max) :val(_spd),min_val(_min),max_val(_max) {};
		~SPeed() {};
	public:
		void Accel(float _accel) {
			if (val >= max_val) return;
			val *= _accel;
		}
		void Normalization() {
			if (val > max_val) val = max_val;
			if (val < min_val) val = min_val;
		}
		float GetSpeed() { return val; }
	private:
		float val;		// 現在の速度
		float min_val;		// 最低速度
		float max_val;		// 最高速度
	};

}