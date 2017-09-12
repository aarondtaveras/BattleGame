/*
 * AllUnits.h
 *
 *  Created on: May 1, 2017
 *      Author: AD
 */

#ifndef ALLUNITS_H_
#define ALLUNITS_H_
#include <vector>

/*
 * Hello Professor, this is my Home Project#3. Each function has been tested to correctly work and return the proper values.
 * This is my AllUnits header file, which contains all proper declarations for members of AllUnits class as well as Units class.
 * @Aaron Taveras
 */
enum Under_Command_of{PLAYER,COMPUTER};

class AllUnits{

public:
	class Unit{
	private:
		int x;int y;
		unsigned short size;unsigned short hp;
		unsigned short armor;unsigned short base_impact;
		Under_Command_of owner;
	public:
		Unit();
		Unit(int x_val,int y_val,unsigned short size_val,unsigned short hp_val,unsigned short armor_val,unsigned short base_impact_val,Under_Command_of owner_val);
		void SetX(const int x_val);
		int GetX()const;
		void SetY(const int y_val);
		int GetY()const;
		void SetSize(const unsigned short size_val);
		unsigned short GetSize()const;
		void SetHp(const unsigned short hp_val);
		unsigned short GetHp()const;
		void SetArmor(const unsigned short armor_val);
		unsigned short GetArmor()const;
		void SetBase_Impact(const unsigned short base_impact_val);
		unsigned short GetBase_Impact()const;
		void SetOwner(const Under_Command_of owner_val);
		Under_Command_of GetOwner()const;

	};
	AllUnits();
	~AllUnits();
	int GetUnit(const int x,const int y) const;
	int SelectUnit(const int x,const int y);
	std::vector <int> SelectUnits(const int x1,const int y1,const int x2,const int y2);
	void AddUnit(const Unit& new_unit);
	bool MoveUnit(const int i,const int new_x,const int new_y);
	void Affect(const int target_index);
	void PrintUnit(const int i)const;
	void PrintSelectedUnits()const;
	void PrintAllUnits()const;

private:

	std::vector<Unit> all;
	std::vector<int> selected;

};


#endif /* ALLUNITS_H_ */
