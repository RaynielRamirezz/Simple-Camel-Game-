/* Rayniel Ramirez

The Camel Game

*/

#include <iostream> //libraries that I used
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	bool done = false;
	
	int user_miles_traveled = 0, // integers variables 
	    thirst = 0,
	    camel_tiredness = 0,
	    natives_distance = -20,
	    drinks_canteen = 3,
		oasis = 0;
	    
const int max_native = 14, // constant integer variables for formula that 
          min_native = 7,  //generate random numbers
          min_oasis = 1,
          max_oasis = 20;
          
		      
cout << "Welcome to camel! " << endl;
cout << "You have stolen a camel to make your way across the great Mobi desert. " << endl;
cout << "The natives want their camel back and are chasing you down! Survive your " << endl;
cout << "desert trek and out run the natives " << endl;	

//The start of the loop
while(done == false){
cout << "A. Drink from your canteen. " << endl;
cout << "B. Ahead moderate speed. " << endl;
cout << "C. Ahead full speed. " << endl;
cout << "D. Stop for the night. " << endl;
cout << "E. Status check. " << endl;
cout << "Q. Quit. " << endl;
cout << "Your choice? ";
char choice;
cin >> choice; //user's choice
cout << endl;

unsigned seed = time(0);
               srand(seed);
oasis = (rand() % (max_oasis - min_oasis + 1)) + min_oasis; //random number for a one-in twenty chance (formula)
                                                            //of finding an oasis
        //choice A
if(choice == 'A' || choice == 'a'){

  if(drinks_canteen > 0){
  		
 drinks_canteen -=1;                    
 thirst = 0;
 
}else if(drinks_canteen == 0){ //This is to print an error if there are no more drinks 
	cout << "Error: No more drinks available for you. " << endl;
	cout << endl;
}
}
       //choice B
else if(choice == 'B' || choice == 'b'){
	const int max_moderate_speed =12, //constant integers for random number from 5 to 12
	          min_moderate_speed = 5;
	          
    unsigned seed = time(0); //these two statements are needed so that the 
               srand(seed);  //formula is able to generate random numbers
			
		//formula for a random number from 5 to 12 (moderate speed)
	    user_miles_traveled += (rand() % (max_moderate_speed - min_moderate_speed + 1)) + min_moderate_speed;
	     
	    cout << "You traveled " << user_miles_traveled << " miles" << endl;
	    cout << endl;
	    
	    thirst +=1;
	    
	    camel_tiredness +=1;
	    
	    //formula for a random number from 7 to 14 (natives)
	    natives_distance += (rand() % (max_native - min_native + 1)) + min_native;	

}
             //choice C
else if(choice == 'C' || choice ==  'c'){
	const int min_user_traveled = 10,
	      max_user_traveled = 20,
	      min_camel_tiredness = 1,  //constant integers for random numbers
	      max_camel_tiredness = 3;
	      
	      unsigned seed = time(0);
				srand(seed);
				 
		//formula for a random number from 10 to 20 (full speed)
	    user_miles_traveled += (rand() % (max_user_traveled - min_user_traveled + 1)) + min_user_traveled;
	     
	    cout << "You traveled " << user_miles_traveled << " miles" << endl;
	    cout << endl;
	    
	    thirst +=1;
	    
	    //formula for a random number from 1 to 3 (camel tiredness)
	    camel_tiredness += (rand() % (max_camel_tiredness - min_camel_tiredness + 1)) + min_camel_tiredness;
	    
	    //formula for a random number from 7 to 14 (natives)
	    natives_distance += (rand() % (max_native - min_native + 1)) + min_native;
	    
	
} 
       //choice D
else if(choice == 'D' || choice ==  'd'){
           camel_tiredness = 0; //reset camel tiredness to cero
           unsigned seed = time(0);
				srand(seed);
				 
    cout << "The camel is happy! " << endl;
    cout << endl;
    
    //formula for a random number from 7 to 14 (natives)
    natives_distance += (rand() % (max_native - min_native + 1)) + min_native;
	   
	   //choice E
}else if(choice == 'E' || choice ==  'e'){
	cout << "Miles traveled : " << user_miles_traveled << endl;
	cout << "Drinks in canteen: " << drinks_canteen << endl;
	cout << "The natives are " << user_miles_traveled - natives_distance << " miles behind you. " << endl;
	cout << endl;
	//in the cout statement that says the natives are miles behind you,
	//i did this by substracting the user's miles with the native's miles to find
	//out how many miles they are behind the user
	
	//if thirst is in a range between 5 and 6 then print "You are thirsty"
}if(thirst > 4 && thirst <=6){
	cout << "You are thirsty. " << endl;
	cout << endl;

    //else if thirst is more than 6, print "You died of thirst" and end the game
}else if(thirst > 6){
	    camel_tiredness = 0;
	cout << "You died of thirst! " << endl;
	cout << endl;
	
	    done = true; //this is to end the loop (end the game)
	   
	//if range from 6 to 8 (camel tiredness) to pring "Your camel is getting tired" 
}if(camel_tiredness > 5 && camel_tiredness <= 8){
	cout << "Your camel is getting tired. " << endl;
	cout << endl;
	
	//else if camel tiredness is more than 8, pring "Your camel is dead"
	//and end the game
}else if(camel_tiredness > 8){
	    thirst =0;
	cout << "Your camel is dead " << endl;
	cout << endl;
	
	    done = true;
	
	//if the natives are more than or equal than the user, then print
	// "The natives have caught you" and end the game
}if(natives_distance >= user_miles_traveled){
	 thirst =0;
	 camel_tiredness = 0;
	
	cout << "The natives have caught you! " << endl;
	cout << endl;
	
	    done = true;
	    
	//else if the natives are less 15 miles behind, print "The natives are getting close!"
	//(I did this by substracting the user's miles and the native's miles)
}else if(user_miles_traveled - natives_distance < 15 ){
	cout << "The natives are getting close! " << endl;
	cout << endl;
	
}

    //if the user's miles are more than or equal to 200 then print "You have won the game!"
    //and end the game
 if(user_miles_traveled >= 200){
        natives_distance = 0;
	    thirst = 0;
	    camel_tiredness = 0;
	
	cout << "You made it across the desert, you have won the game! " << endl;
	cout << endl;

	    done = true;
			 
			    
	//This else if is to see if the user is lucky enough to find the oasis
	//if they find it, they get their stuff back (restored)
	//they won't find the oasis if they click on 'E' or 'e' since that's
	//cheating. 'E' or 'e' is only to look at your status		    
}else if(done == false && oasis == 20 && choice != 'E' && choice != 'e'){
	
	 drinks_canteen = 3;
	 thirst = 0;
	 camel_tiredness = 0;
	
	cout << "You found the oasis! " << endl;
	cout << endl;
}

    
    //choice Q
else if(choice == 'Q' || choice ==  'q'){
    cout << "You quit the game. " << endl;
    
	    done = true;	
	   	   
} 

}


    system ("Pause");
	return 0;
}