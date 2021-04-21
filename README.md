## Time Complexity:
   Create, read and delete = O(1) (consant time )
## Space Complexity:
   space complexity is linear = O(n) 
   where n is the number of key-value pair
## Concept for storing the data
   i have used **hashing with chaining** concept for storing the data(key-value pair) and this result in a constant time access and minimum space complexity.
   
## Working
   program starts execute from the main function 
   object of **CRD** class is created in the main function.
   
   NOTE- key- value data will be as follow : key is string (example: nickname of the person)
                                             value is of JSON object (JSON will store two value ( example: name of the person and the age))
                                             
   calling the operations function of the **CRD** class to take the user operation input.
 ## operation() function :
           now user have 6 option :
                        1 : create :              adding the data and Create() function will be called
                        2 : read   :              read() function will be called
                        3 : delete :              delete() function will be called
                        4 : clear  :              if we want to clear the screen 
                        5 : optional file path:   input the file to initialise(must be 'input.txt' name)
                        6 : exit :                stop the program
                        
  ## Create() function :
   will take key- value pair input from the user(eg - nickname of the person as key then JSON object as Name and the age of the person) 
   and check whether this key exist or not if not then add else give a warning message that data alreday exist.
   
  ## read() function :
   will take the input as a key(string) from the user and to check whether that particular key exist or not and give proper message accordingly.
  ## delete() function:
   will take the input as a key(string) from the user and to check whether that particular key exist or not and give proper message accordingly.
  ## clear() function:
   this is basically to clear the console(screen).
  ## optional file path (option 5):
   this will take input from the file and call create() function accordingly to to create the data.  
