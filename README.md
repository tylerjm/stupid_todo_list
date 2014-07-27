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

To use todo:

Just compile it (I do: g++ -o todo todo.cpp), then put the resulting binary in your bin folder, which is presumably in your PATH, or put an alias to it in your .bashrc