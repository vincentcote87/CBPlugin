CXX=g++
CXXFLAGS= -std=c++11 -c
SHARED_LIBFLAG = -fPIC
OFLAG = -o

CB_INCLUDE = /usr/include/codeblocks/
WX_INCLUDE = /usr/include/wx-2.8/
SRC_INCLUDE = 
SRC_DIR = 

.PHONY: all
all: createlib zip

createlib:	
	$(CXX) $(CXXFLAGS) *.cpp $(SHARED_LIBFLAG) -I $(CB_INCLUDE) -I $(WX_INCLUDE)

zip: createlib
	zip -j9 ImplementationGenerator.zip manifest.xml
	zip -j9 ImplementationGenerator.cbplugin ImplementationGenerator.so ImplementationGenerator.zip


.PHONY: clean
clean: 

	rm -rf *~ *.layout *.cbplugin *.so *.depend *.zip ./testPlugin
