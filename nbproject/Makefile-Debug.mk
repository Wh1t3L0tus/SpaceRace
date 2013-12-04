#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Background/Star.o \
	${OBJECTDIR}/src/Background/StarBackground.o \
	${OBJECTDIR}/src/Background/StarField.o \
	${OBJECTDIR}/src/Collider/Collider.o \
	${OBJECTDIR}/src/ContentManager/ContentManager.o \
	${OBJECTDIR}/src/Entity/Entity.o \
	${OBJECTDIR}/src/Entity/MobManager.o \
	${OBJECTDIR}/src/Entity/Player.o \
	${OBJECTDIR}/src/Entity/SpaceShip.o \
	${OBJECTDIR}/src/GameState/GameOverState.o \
	${OBJECTDIR}/src/GameState/IntroState.o \
	${OBJECTDIR}/src/GameState/MenuState.o \
	${OBJECTDIR}/src/GameState/PauseState.o \
	${OBJECTDIR}/src/GameState/RaceState.o \
	${OBJECTDIR}/src/GameState/StateManager.o \
	${OBJECTDIR}/src/Gui/RaceGui.o \
	${OBJECTDIR}/src/Random.o \
	${OBJECTDIR}/src/ScoreManager/ScoreManager.o \
	${OBJECTDIR}/src/Spawner/ScriptedSpawner.o \
	${OBJECTDIR}/src/Spawner/Spawner.o \
	${OBJECTDIR}/src/WavesLoader/Wave.o \
	${OBJECTDIR}/src/WavesLoader/WavesLoader.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wextra -pedantic
CXXFLAGS=-Wextra -pedantic

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -Wl,-rpath,/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -ljson_linux-gcc-4.7_libmt

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk spacerace_debug

spacerace_debug: ${OBJECTFILES}
	${LINK.cc} -o spacerace_debug ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Background/Star.o: src/Background/Star.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Background
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Background/Star.o src/Background/Star.cpp

${OBJECTDIR}/src/Background/StarBackground.o: src/Background/StarBackground.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Background
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Background/StarBackground.o src/Background/StarBackground.cpp

${OBJECTDIR}/src/Background/StarField.o: src/Background/StarField.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Background
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Background/StarField.o src/Background/StarField.cpp

${OBJECTDIR}/src/Collider/Collider.o: src/Collider/Collider.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Collider
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Collider/Collider.o src/Collider/Collider.cpp

${OBJECTDIR}/src/ContentManager/ContentManager.o: src/ContentManager/ContentManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ContentManager
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ContentManager/ContentManager.o src/ContentManager/ContentManager.cpp

${OBJECTDIR}/src/Entity/Entity.o: src/Entity/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Entity
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Entity/Entity.o src/Entity/Entity.cpp

${OBJECTDIR}/src/Entity/MobManager.o: src/Entity/MobManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Entity
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Entity/MobManager.o src/Entity/MobManager.cpp

${OBJECTDIR}/src/Entity/Player.o: src/Entity/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Entity
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Entity/Player.o src/Entity/Player.cpp

${OBJECTDIR}/src/Entity/SpaceShip.o: src/Entity/SpaceShip.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Entity
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Entity/SpaceShip.o src/Entity/SpaceShip.cpp

${OBJECTDIR}/src/GameState/GameOverState.o: src/GameState/GameOverState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GameState
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameState/GameOverState.o src/GameState/GameOverState.cpp

${OBJECTDIR}/src/GameState/IntroState.o: src/GameState/IntroState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GameState
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameState/IntroState.o src/GameState/IntroState.cpp

${OBJECTDIR}/src/GameState/MenuState.o: src/GameState/MenuState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GameState
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameState/MenuState.o src/GameState/MenuState.cpp

${OBJECTDIR}/src/GameState/PauseState.o: src/GameState/PauseState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GameState
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameState/PauseState.o src/GameState/PauseState.cpp

${OBJECTDIR}/src/GameState/RaceState.o: src/GameState/RaceState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GameState
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameState/RaceState.o src/GameState/RaceState.cpp

${OBJECTDIR}/src/GameState/StateManager.o: src/GameState/StateManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GameState
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameState/StateManager.o src/GameState/StateManager.cpp

${OBJECTDIR}/src/Gui/RaceGui.o: src/Gui/RaceGui.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Gui
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Gui/RaceGui.o src/Gui/RaceGui.cpp

${OBJECTDIR}/src/Random.o: src/Random.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Random.o src/Random.cpp

${OBJECTDIR}/src/ScoreManager/ScoreManager.o: src/ScoreManager/ScoreManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ScoreManager
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ScoreManager/ScoreManager.o src/ScoreManager/ScoreManager.cpp

${OBJECTDIR}/src/Spawner/ScriptedSpawner.o: src/Spawner/ScriptedSpawner.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Spawner
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Spawner/ScriptedSpawner.o src/Spawner/ScriptedSpawner.cpp

${OBJECTDIR}/src/Spawner/Spawner.o: src/Spawner/Spawner.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Spawner
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Spawner/Spawner.o src/Spawner/Spawner.cpp

${OBJECTDIR}/src/WavesLoader/Wave.o: src/WavesLoader/Wave.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/WavesLoader
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/WavesLoader/Wave.o src/WavesLoader/Wave.cpp

${OBJECTDIR}/src/WavesLoader/WavesLoader.o: src/WavesLoader/WavesLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/WavesLoader
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/WavesLoader/WavesLoader.o src/WavesLoader/WavesLoader.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O3 -Wall -I/usr/local/include -Isrc/Background -Isrc/Collider -Isrc/ContentManager -Isrc/Entity -Isrc/GameState -Isrc/Gui -Isrc/Spawner -Isrc -Isrc/WavesLoader -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} spacerace_debug

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
