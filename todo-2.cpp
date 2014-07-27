/*
  todo.cpp
  Author: Tyler J. Mobray
  Version: 0.1
  Date Created: June 2nd, 2014
  Last Modified: June 2nd, 2014

  todo expects two arguments: the operation to complete (add/remove/list), and either a string which describes 
  (in English prose) the task to be added to the list, or the number of the task to be removed.

  example: $> todo add "fix stupid bugs"
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
using namespace std;

int main(int argc, char* argv[])
{
  string mode = argv[1];
  cout << "argument is: " << mode << endl;
  if(mode == "add")
    {
      ofstream write_todo_list;
      write_todo_list.open("todo_list.txt", std::ofstream::out | std::ofstream::app);
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
      cout << "argument was: list" << endl;
      ifstream read_todo_list;
      read_todo_list.open("todo_list.txt");
      while (getline (read_todo_list,line))
	{
	  cout << line << endl;
	}
	read_todo_list.close();
    }
  if(mode == "remove")
    {
      cout << "argument was: remove" << endl;
      string temp;
      string rest_of_file;
      ifstream read_todo_list;
      ofstream write_todo_list;
      read_todo_list.open("todo_list.txt");
      int count = 0;
      int line_to_remove = atoi(argv[2]);
      cout << "removing line: " << line_to_remove << endl;
      while(getline(read_todo_list,temp))
	{
	  if(count != line_to_remove)
	    {
	      rest_of_file = rest_of_file + temp;
	      count ++;
	    }
	  if(count == line_to_remove)
	    {
	      cout << "temp cleared" << endl;
	      temp.clear();
	      rest_of_file = rest_of_file + temp;
	      count ++;
	    }
	}
      read_todo_list.close();
      write_todo_list.open("todo_list.txt");
      write_todo_list << rest_of_file;
      write_todo_list.close();
    }
  if(mode != "add" && mode != "list" && mode != "remove")
    {
      cout << "todo: invalid command. use add, remove, or list" << endl;
    }

  return 0;
}

