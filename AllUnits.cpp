/*
 * AllUnits.cpp
 *
 *  Created on: May 1, 2017
 *      Author: AD
 */

#include "AllUnits.h"
#include <iostream>
#include <vector>
#include <string>

/*
 * Here is my AllUnits.cpp class. AllUnits class as well as Units class have each been implemented within this file.
 * @Aaron Taveras
 */

	AllUnits::Unit::Unit(){
		x = 1;
		y = 1;
		size = 5;
		hp = 10;
		armor = 2;
		base_impact = 4;
		owner = {PLAYER};
	}

	AllUnits::Unit::Unit(int x_val,int y_val,unsigned short size_val,unsigned short hp_val,unsigned short armor_val,unsigned short base_impact_val,Under_Command_of owner_val){
		x = x_val;
		y = y_val;
		size = size_val;
		hp = hp_val;
		armor = armor_val;
		base_impact = base_impact_val;
		owner = owner_val;
	}

	void AllUnits::Unit::SetX(const int x_val){
					x = x_val;
				}

	int AllUnits::Unit::GetX ()const{
					return x;
				}

	void AllUnits::Unit::SetY(const int y_val){
					y = y_val;
				}

	int AllUnits::Unit::GetY() const{
					return y;
				}
	void AllUnits::Unit::SetSize(const unsigned short size_val){
					size = size_val;
				}
	unsigned short AllUnits::Unit::GetSize()const{
					return size;
				}
	void AllUnits::Unit::SetHp(const unsigned short hp_val){
					hp = hp_val;
				}
	unsigned short AllUnits::Unit::GetHp()const{
					return hp;
				}
	void AllUnits::Unit::SetArmor(const unsigned short armor_val){
					armor = armor_val;
				}
	unsigned short AllUnits::Unit::GetArmor()const{
					return armor;
				}
	void AllUnits::Unit::SetBase_Impact(const unsigned short base_impact_val){
					base_impact = base_impact_val;
				}
	unsigned short AllUnits::Unit::GetBase_Impact()const{
					return base_impact;
				}
	void AllUnits::Unit::SetOwner(const Under_Command_of owner_val){
					owner = owner_val;
				}
	Under_Command_of AllUnits::Unit::GetOwner()const{
					return owner;
				}

	AllUnits::AllUnits(){}

	AllUnits::~AllUnits(){
		std::vector<Unit>().swap(all);
		std::vector<int>().swap(selected);
	}

	//Works
	int AllUnits::GetUnit(const int x,const int y)const{
		for(std::size_t i=0,max = all.size();i!=max; i++){
			if(all[i].GetX() == x && all[i].GetY() == y){
				return i;
			}
		}
		return -1;
	}

	//Works
	int AllUnits::SelectUnit(const int x,const int y){
		selected.clear();
		for(std::size_t i=0,max = all.size();i != max; i++){
			if(all[i].GetX() == x && all[i].GetY() == y && all[i].GetOwner() == 0){
				selected.push_back(i);
			}
			else {
				std::cout << "Cannot select unit. Check X, Y and Owner values.";
				return -1;
			}
		}
		return selected[0];
	}

	//Works

	std::vector<int> AllUnits::SelectUnits(const int x1,const int x2,const int y1,const int y2){
		selected.clear();
		for(std::size_t i=0,max = all.size();i!=max; i++){
				int xrightval,xleftval,yupval,ylowval;
				xrightval = all[i].GetX()+all[i].GetSize()/2;
				xleftval = all[i].GetX()-all[i].GetSize()/2;
				yupval = all[i].GetY()+all[i].GetSize()/2;
				ylowval = all[i].GetY()-all[i].GetSize()/2;
				if(all[i].GetOwner()==0){
				if((xleftval <= x2 && xleftval >= x1) || (xrightval <=x2 && xrightval >=x1)){
					if((yupval <= y2 && yupval >= y1)||(ylowval <= y2 && ylowval >= y1)){
						selected.push_back(i);
					}
				}

				else if((x1 <= xrightval && x1 >= xleftval) || (x2 <=xrightval && x2 >=xleftval)){
					if((y1 <= yupval && y1 >= ylowval)||(y2 <= yupval && y2 >= ylowval)){
						selected.push_back(i);
					}
				}
				else selected.clear();
			}
		}
		return selected;
	}

	//Works

	void AllUnits::AddUnit(const Unit& new_unit){
		all.push_back(new_unit);
	}
	bool AllUnits::MoveUnit(const int i,const int new_x,const int new_y){
		for(std::size_t j=0,max=all.size();j!=max;j++){
			int xrightbound,xleftbound,yupbound,ylowbound;
			xrightbound = all[j].GetX()+all[j].GetSize()/2;
			xleftbound = all[j].GetX()-all[j].GetSize()/2;
			yupbound = all[j].GetY()+all[j].GetSize()/2;
			ylowbound = all[j].GetY()-all[j].GetSize()/2;
			if(new_x >= xleftbound && new_x <= xrightbound){
				std::cout<<"Position occupied.";
				return false;
			}
			else if(new_y >= ylowbound && new_y <= yupbound){
				std::cout<<"Position occupied.";
				return false;
			}
			else all[i].SetX(new_x),all[i].SetY(new_y);
		}
		return true;
	}

	//Works

	void AllUnits::Affect(const int target_index){
		for(std::size_t i=0,max = selected.size();i!=max;i++){
			if(all[(selected[i])].GetBase_Impact()<all[target_index].GetArmor()){

			}
			if(all[target_index].GetHp()>all[(selected[i])].GetBase_Impact()-all[target_index].GetArmor()){
				unsigned short newhp = all[target_index].GetHp() - all[(selected[i])].GetBase_Impact()+all[target_index].GetArmor();
				all[target_index].SetHp(newhp);
			}
			else if(all[target_index].GetHp()-all[(selected[i])].GetBase_Impact()+all[target_index].GetArmor() <= 1){
				all.erase(all.begin()+target_index);
				std::cout<< "Unit at index " << i << " has been defeated.";
				std::cout<<std::endl;
				for(std::size_t j=0,max = selected.size();j!=max;j++){
					if(selected[j]==target_index){
						selected.erase(selected.begin()+j);
					}
				}
			}
		}
	}
	//Works

	void AllUnits::PrintUnit(const int i)const{
		std::size_t j = i;
		if(j > all.size()){
			std::cout<< "No existing Unit at location.";
			std::cout<<std::endl;
		}
		std::cout<< "Unit X: " << all[i].GetX()<< " Unit Y: " << all[i].GetY()<< " Unit HP: " << all[i].GetHp() << " Unit Armor: " << all[i].GetArmor() << " Unit Base Impact: " << all[i].GetBase_Impact() << " Unit Size: " <<
		all[i].GetSize() << " Unit Owner: " << all[i].GetOwner();
	}
	//Works
	void AllUnits::PrintSelectedUnits()const{
		if(selected.size()== 0){
			std::cout << "No Units currently selected.";
			std::cout<<std::endl;
		}
		for(std::size_t i=0,max = selected.size();i!=max;i++){
			std::cout << "Selected Unit #" << i+1 << " index: " << selected[i];
			std::cout<<std::endl;
		}
	}
	//Works

	void AllUnits::PrintAllUnits()const{
		if(all.size()==0){
			std::cout << "No Units added to game yet.";
		}
		for(std::size_t i=0,max = all.size();i!=max;i++){
			PrintUnit(i);
			std::cout<<std::endl;
		}
	}



