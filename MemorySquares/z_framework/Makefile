vpath %.cpp zf_common
vpath %.cpp zf_sfml
vpath %.cpp zf_sfml/animations

WARNING= -Wextra -Wno-switch -Wno-sign-compare -Wno-missing-braces -Wno-unused-parameter
OPTIMIZE= -fno-exceptions

CXX=clang++ ${WARNING}

OBJDIR=obj

common = $(shell (cd zf_common ; ls *.cpp ))
commonobjs = $(patsubst %, $(OBJDIR)/% , $(common:.cpp=.o))

sfml = $(shell cd zf_sfml ; ls *.cpp )
sfmlobjs = $(patsubst %, $(OBJDIR)/% , $(sfml:.cpp=.o))

sfmlsubdir = $(shell cd zf_sfml ; for F in `ls -d */` ; do cd $$F ; ls *.cpp ; cd .. ; done )
sfmlsubdirobjs = $(patsubst %, $(OBJDIR)/%, $(sfmlsubdir:.cpp=.o))

all: $(commonobjs) $(sfmlobjs) $(sfmlsubdirobjs) 

$(OBJDIR)/%.o : %.cpp
	$(CXX) -c -o $@ $^

clean:
	rm obj/*.o

remake:
	make clean
	make all

debug:
	@echo $(world)
.PHONY: clean remake debug
