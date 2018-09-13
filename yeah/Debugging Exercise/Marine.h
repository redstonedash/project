#pragma once
class 
{
	public:
		Marine();
		~Marine();

		virtual int attack();
		virtual void takeDamage(int damage);
		bool isAlive();

	private:
		int health;
		int maxHealth;
};
