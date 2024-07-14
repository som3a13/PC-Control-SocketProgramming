#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <signal.h>

int exe(const std::string &command)
{

            /******************Forking a child process***************************/
        pid_t pid = fork();
        if (pid == 0) {  
        char *argv[] = {const_cast<char*>("/bin/sh"), const_cast<char*>("-c"), const_cast<char*>(command.c_str()), nullptr};
        execvp(argv[0], argv);
                // execlp("sh", "sh", "-c", command.c_str(), nullptr);
    
            std::cerr << "Child: Failed to execute  process." << std::endl;
            exit(1);
        } else if (pid > 0) {  

            /*nothing*/
            
            } else {
            std::cerr << "Failed to fork" << std::endl;
            return 1;
        }
    return 0;
}
int main()
{

    while(1)
    {   
        std::string command;
        std::cout << "Enter command : "; 
    std::getline(std::cin,command);
    
        if(command!="exit")
        {
            exe(command);
        }
        else
        {
            break;
        }
    }
    std::cout << std::endl; // Add a blank line before prompting again

    return 0;
}