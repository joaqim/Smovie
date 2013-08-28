# 
#   Default make file 
# 

######## 
#   Directories 
S_DIR=Source 
B_DIR=Build 

######## 
#   Output 
EXEC=$(B_DIR)/SDL_test.exec 
    
# default build settings 
##  debug setup 
CC_OPTS=-c -pipe -Wall -Wno-switch -ggdb -g3  
LN_OPTS= 
CC=g++ 
##  release setup 
#C_OPTS=-c -pipe 
#LN_OPTS= 
#CC=g++ 

######## 
#       SDL options 
CC_SDL=-I/usr/local/include/SDL -D_REENTRANT 
LN_SDL=-L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL -lSDL_image -lpthread 

######## 
#   This is the default action 
all:Build 


######## 
#   Object list 
# 
OBJ = $(B_DIR)/main.o 


######## 
#   Objects 
$(B_DIR)/main.o : $(S_DIR)/main.cpp $(S_DIR)/game.h 
	$(CC) $(CC_OPTS) -o $(B_DIR)/main.o $(S_DIR)/main.cpp $(CC_SDL) 


######## 
#   Main build rule      
Build : $(OBJ) Makefile 
	$(CC) $(LN_OPTS) -o $(EXEC) $(OBJ) $(LN_SDL) 


clean: 
	rm -f $(B_DIR)/* 
