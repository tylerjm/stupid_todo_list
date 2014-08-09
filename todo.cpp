/*
  todo.cpp
  Author: Tyler J. Mobray
  Version: 0.1
  Date Created: June 2nd, 2014
  Last Modified: June 2nd, 2014

  todo expects two arguments: the operation to complete (add/remove/list), and either a string which describes 
  (in English prose) the task to be added to the list, or the number of the task to be removed.

  todo also expects that it lives in the bin folder in your home directory.

  example: 

           $> todo add "fix stupid bugs"
           $> todo: added task [0]: "fix stupid bugs"

	   $> todo list
	   $> To-Do: 
	      [0]: "fix stupid bugs"
	      END OF LIST

	   $> todo remove 0
	   $> todo removed ta$k [0]: "fix $tupid bug$"
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
  string mode = argv[1];
  char* working_dir;
  char* home_dir;
  
  home_dir = getenv("HOME");
  working_dir = strcat(home_dir, "/bin/todo_list.txt");
  
  if(mode == "add")
    {
      ofstream write_todo_list;
      write_todo_list.open(working_dir, std::ofstream::out | std::ofstream::app);
      for(int i = 2; i < argc ; i++)
	{
	  write_todo_list << argv[i] << " ";
	}
      write_todo_list << endl;
      write_todo_list.close();
    }
  if(mode == "list")
    {
      string line;
      ifstream read_todo_list;
      read_todo_list.open(working_dir);
      while (getline (read_todo_list,line))
	{
	  cout << line << endl;
	}
	read_todo_list.close();
    }
  if(mode == "remove")
    {
      string temp;
      string rest_of_file;
      ifstream read_todo_list;
      ofstream write_todo_list;
      read_todo_list.open(working_dir);
      int count = 0;
      int line_to_remove = atoi(argv[2]);
      while(getline(read_todo_list,temp))
	{
	  if(count != line_to_remove)
	    {
	      rest_of_file = rest_of_file + temp;
	      count ++;
	    }
	  if(count == line_to_remove)
	    {
	      temp.clear();
	      rest_of_file = rest_of_file + temp;
	      count ++;
	    }
	}
      read_todo_list.close();
      write_todo_list.open(working_dir);
      write_todo_list << rest_of_file;
      write_todo_list.close();
    }
  if(mode != "add" && mode != "list" && mode != "remove")
    {
      cout << "todo: invalid command. use add, remove, or list" << endl;
    }

  return 0;
}

