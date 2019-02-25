OBJSDIR =		src
HEADERSDIR =	headers
OBJS =			$(patsubst %.cpp,%.o,$(wildcard $(OBJSDIR)/**/*.cpp))
HEADERDIRS =	$(addprefix -I, $(sort $(dir $(wildcard $(OBJSDIR)/**/$(HEADERSDIR)/*.h))))

CXX =			g++
CXXFLAGS = 		$(HEADERDIRS) -std=c++0x -Wall
LDFLAGS =		-pthread

LIBS =			
TARGET =		loadbalancer

$(TARGET):		$(OBJS)
				$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

all:
				$(TARGET)

clean:
				rm -f $(OBJS) $(TARGET)