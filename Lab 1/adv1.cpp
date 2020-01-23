//This C++ code is used to take an input string and
// put the instructions in an array
#include <iostream>
#include <string>
#include <sstream>


int main() { 
    //set up input string
    std::string input="orange lift right";
    bool flag = false;

    //set up map with instruction sets
    std::string time[4] = {"1second", "2seconds", "5seconds", "unlimited"};
    std::string move[5] = {"left", "right", "forward", "backward", "stop"};
    std::string object[5] = {"orange", "apple", "car", "bus", "diamond"};
    std::string action[6] = {"recognise", "eat", "see", "lift", "drop", "fetch"};
    std::string size[4] = { "small", "big", "little", "massive"};
    std::string location[3] = {"door", "kitchen", "table"};
    
    //initalise input stream
    std::stringstream currentstring(input);
    int count=-1;
    std::string instruction[10];

    //Repeatedly put instruction in string array
    while (currentstring.good())
    {
        count=count+1;
        currentstring >> instruction[count];
        std::cout << instruction[count] << " - - / - - " << sizeof(instruction)/sizeof(*instruction) << std::endl;
    }

    //check for string structure
    if(count == 1)
    {
        //check if instructions are of type <Move> <Time>
        std::cout << "<Move> <Time>" << std::endl;

        for(int i = -1; i < 5; i++)
        {
            if(instruction[0] == move[i])
            {
                std::cout << "Check" << std::endl;                        
                break;
            }
            else
            {
                if(i == 4)
                {
                    std::cout << "First bad" << std::endl;
                    return 0;
                } 
            }
        }

        for(int i = -1; i < 4; i++)
        {
            if(instruction[1] == time[i])
            {
                std::cout << "Check" << std::endl;     
                break;              
            }
            else
            {
                if(i == 3)
                {
                    std::cout << "Second bad" << std::endl;
                    return 0;
                } 
            }
        }
    return 0;        
    }

    else if(count == 2)
    {
        /*check if instructions are of type <Object> <Action> <Time> ...*/
        std::cout << "<Object> <Action> <Time> ..." << std::endl;

        //check if first string is object if not then check if it is location if not then error
        //Check object for first word
        for(int i = -1; i < 5; i++)
        {
            if(instruction[0] == object[i])
            {
                //check if it is action or size
                //check action for second word
                for(int i = -1; i < 6; i++)
                {
                    if(instruction[1] == action[i])
                    {
                        //check time for third word
                        for(int i = -1; i < 4; i++)
                        {
                            if(instruction[2] == time[i])
                            {
                                std::cout << "Check" << std::endl; 
                                flag = true;                       
                                break;                                
                            }
                            if(flag == true)
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        //check size for second word
                        for(int i = -1; i < 4; i++)
                        {
                            if(instruction[1] == size[i])
                            {
                                //check action for third word
                                for(int i = -1; i < 4; i++)
                                {
                                    if(instruction[2] == action[i])
                                    {   
                                        std::cout << "Check" << std::endl;
                                        flag = true;                        
                                        break;                                
                                    }
                                    if(flag == true)
                                    {
                                        break;
                                    }
                                    
                                }                                
                            }
                            if(flag == true)
                            {
                                break;
                            }
                        }
                    }
                    if(flag == true)
                    {
                        break;
                    }
                    
                }
                if(flag == true)
                {
                    break;
                }
            }
            else
            {
                //Check location for first word
                for(int i = -1; i < 3; i++)
                {
                    if(instruction[0] == location[i])
                    {
                        //check action for second word
                        for(int i = -1; i < 6; i++)
                        {
                            if(instruction[1] == action[i])
                            {
                                //check object for third word
                                for(int i = -1; i < 5; i++)
                                {
                                    if(instruction[2] == object[i])
                                    {
                                        std::cout << "Check" << std::endl; 
                                        flag = true;                       
                                        break; 
                                    }
                                    if(flag == true)
                                    {
                                        break;
                                    }
                                }
                            }
                            if(flag == true)
                            {
                                break;
                            }
                        }
                    }
                    if(flag == true)
                    {
                        break;
                    }
                }    
            }
            if(flag == true)
            {
                break;
            }

            if(i == 4)
                std::cout << "Not the right syntax" << std::endl;    
        }
        return 0;
    }
    else if(count == 3)
    {
        //check if instructions are of type <Move> <Time> <Move> <Time>
        std::cout << "<Move> <Time> <Move> <Time>" << std::endl;

        for(int i = -1; i < 5; i++)
        {
            if(instruction[0] == move[i])
            {
                std::cout << "Check" << std::endl;                        
                break;
            }
            else
            {
                if(i == 4)
                {
                    std::cout << "First bad" << std::endl;
                    return 0;
                } 
            }
        }

        for(int i = -1; i < 4; i++)
        {
            if(instruction[1] == time[i])
            {
                std::cout << "Check" << std::endl;     
                break;              
            }
            else
            {
                if(i == 3)
                {
                    std::cout << "Second bad" << std::endl;
                    return 0;
                } 
            }
        }

        for(int i = -1; i < 5; i++)
        {
            if(instruction[2] == move[i])
            {
                std::cout << "Check" << std::endl;                        
                break;
            }
            else
            {
                if(i == 4)
                {
                    std::cout << "Third bad" << std::endl;
                    return 0;
                } 
            }
        }

        for(int i = -1; i < 4; i++)
        {
            if(instruction[3] == time[i])
            {
                std::cout << "Check" << std::endl;     
                break;              
            }
            else
            {
                if(i == 3)
                {
                    std::cout << "Fourth bad" << std::endl;
                    return 0;
                } 
            }
        }
    return 0;
        
    }
    else
    {
        std::cout << "That syntax is not understandable by the robot.";
    }
    
    return 0;
}