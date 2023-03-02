# C++ Prüfung, Bialonski/Terstegge/Voss

# Alle Arten von Windows
ifeq ($(OS),Windows_NT)
    BIN_EXT         = .exe
    CMD_UNIX_STYLE  = 0
else
# Alle anderen Betriebssysteme (Linux, MAC)
    BIN_EXT         = 
    CMD_UNIX_STYLE  = 1
endif

ifeq ($(CMD_UNIX_STYLE),1)
    # Unix commands
    RM = rm -f
else
    # Windows commands
    RM =  del /F /Q
endif

ZIP_PREFIX = CPP_
CXX        = g++
CXXFLAGS   = -ansi -pedantic -Wall -Wextra -Wconversion -std=c++17 -g -pthread

SRCS = a1.cpp a2.cpp a3.cpp
BINS = $(SRCS:.cpp=$(BIN_EXT))

all:	$(BINS)

%$(BIN_EXT):%.cpp
	$(CXX) $(CXXFLAGS) -o $@  $<

clean:
	$(RM) $(BINS) *.zip *~ dozip OUTPUT.csv

zip:	dozip$(BIN_EXT)
	./dozip$(BIN_EXT) $(ZIP_PREFIX)
	
# DO NOT DELETE
dozip:    ident.h
a1:   a1.cpp a1_named_sensor_manager.h ident.h
a2:   a2.cpp a2_ticker.h ident.h
a3:   a3.cpp a3_sensors.h ident.h

