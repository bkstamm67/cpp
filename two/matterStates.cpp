/***************
 * Name:  Brian Stamm
 * Date: 1.18.15
 * Description:  This program asks the user to input a temperature (F), and then is shows the user the
 * state of four different matters at that temperature.  
 * *************/

#include<iostream>
   
int main(){
	const int ETHYL_fp = (-173), ETHYL_bp = 172, MERC_fp = (-38), MERC_bp = 676, 
	      OXY_fp = (-362), OXY_bp = (-306), WATER_fp = 32, WATER_bp = 212;
	int temp;
//Above, temperatures are constants so they can't be changed.  Also, temp is user input
//Each matter has a freezing point (fp) and boiling point (bp)

	std::cout << "Please enter a whole number in degrees Fahrenheit:  "; //User prompt
	std::cin >> temp;

	std::cout << "Here are the states of various substances at " << temp <<" F: " <<std::endl;
       
//If block for Ethyl
	
	if(temp <= ETHYL_fp){//Determines when a solid
	   std::cout << "Ethyl Alcohol is a solid." << std::endl;
	}
	else if(ETHYL_bp > temp && temp > ETHYL_fp){//Determines when liquid 
	   std::cout << "Ethyl Alchol is a liquid." << std::endl;
	}
	else if(temp >= ETHYL_bp){//Determines when gas
	   std::cout << "Ethyl Alcohol is a gas." << std::endl;
	}

//If block for Mercury, same set up with different temps

	if(temp <= MERC_fp){
	   std::cout << "Mercury is a solid." << std::endl;
	}
	else if(MERC_bp > temp && temp > MERC_fp){
	   std::cout << "Mercury is a liquid." << std::endl;
	}
	else if(temp >= MERC_bp){
	   std::cout << "Mercury is a gas." << std::endl;
	}

//If block for Oxygen, same set up as above

	if(temp <= OXY_fp){
	   std::cout << "Oxygen is a solid." << std::endl;
	}
	else if(OXY_bp > temp && temp > OXY_fp){
	   std::cout << "Oxygen is a liquid." << std::endl;
	}
	else if(temp >= OXY_bp){
	   std::cout << "Oxygen is a gas." << std::endl;
	}

//If block for water, same set up as above

	if(temp <= WATER_fp){
	   std::cout << "Water is a solid." << std::endl;
	}
	else if(WATER_bp > temp && temp > WATER_fp){
	   std::cout << "Water is a liquid." << std::endl;
	}
	else if(temp >= WATER_bp){
	   std::cout << "Water is a gas." << std::endl;
	}

	return 0;
}
