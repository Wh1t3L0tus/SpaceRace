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
CND_PLATFORM=MinGW_Qt-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1324896651/Star.o \
	${OBJECTDIR}/_ext/1324896651/StarBackground.o \
	${OBJECTDIR}/_ext/1324896651/StarField.o \
	${OBJECTDIR}/_ext/1535743739/Collider.o \
	${OBJECTDIR}/_ext/1643742907/ContentManager.o \
	${OBJECTDIR}/_ext/683866282/Entity.o \
	${OBJECTDIR}/_ext/683866282/MobManager.o \
	${OBJECTDIR}/_ext/683866282/Player.o \
	${OBJECTDIR}/_ext/683866282/SpaceShip.o \
	${OBJECTDIR}/_ext/533720680/GameOverState.o \
	${OBJECTDIR}/_ext/533720680/IntroState.o \
	${OBJECTDIR}/_ext/533720680/MenuState.o \
	${OBJECTDIR}/_ext/533720680/PauseState.o \
	${OBJECTDIR}/_ext/533720680/RaceState.o \
	${OBJECTDIR}/_ext/991262536/Random.o \
	${OBJECTDIR}/_ext/694709887/BasicSpawner.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../bin/${CND_CONF}/SpaceRace.exe

../../bin/${CND_CONF}/SpaceRace.exe: ${OBJECTFILES}
	${MKDIR} -p ../../bin/${CND_CONF}
	${LINK.cc} -o ../../bin/${CND_CONF}/SpaceRace ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1324896651/Star.o: ../SpaceRace/Background/Star.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1324896651
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1324896651/Star.o ../SpaceRace/Background/Star.cpp

${OBJECTDIR}/_ext/1324896651/StarBackground.o: ../SpaceRace/Background/StarBackground.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1324896651
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1324896651/StarBackground.o ../SpaceRace/Background/StarBackground.cpp

${OBJECTDIR}/_ext/1324896651/StarField.o: ../SpaceRace/Background/StarField.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1324896651
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1324896651/StarField.o ../SpaceRace/Background/StarField.cpp

${OBJECTDIR}/_ext/1535743739/Collider.o: ../SpaceRace/Collider/Collider.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1535743739
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1535743739/Collider.o ../SpaceRace/Collider/Collider.cpp

${OBJECTDIR}/_ext/1643742907/ContentManager.o: ../SpaceRace/ContentManager/ContentManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1643742907
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1643742907/ContentManager.o ../SpaceRace/ContentManager/ContentManager.cpp

${OBJECTDIR}/_ext/683866282/Entity.o: ../SpaceRace/Entity/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/683866282
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/683866282/Entity.o ../SpaceRace/Entity/Entity.cpp

${OBJECTDIR}/_ext/683866282/MobManager.o: ../SpaceRace/Entity/MobManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/683866282
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/683866282/MobManager.o ../SpaceRace/Entity/MobManager.cpp

${OBJECTDIR}/_ext/683866282/Player.o: ../SpaceRace/Entity/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/683866282
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/683866282/Player.o ../SpaceRace/Entity/Player.cpp

${OBJECTDIR}/_ext/683866282/SpaceShip.o: ../SpaceRace/Entity/SpaceShip.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/683866282
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/683866282/SpaceShip.o ../SpaceRace/Entity/SpaceShip.cpp

${OBJECTDIR}/_ext/533720680/GameOverState.o: ../SpaceRace/GameState/GameOverState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/533720680
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/533720680/GameOverState.o ../SpaceRace/GameState/GameOverState.cpp

${OBJECTDIR}/_ext/533720680/IntroState.o: ../SpaceRace/GameState/IntroState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/533720680
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/533720680/IntroState.o ../SpaceRace/GameState/IntroState.cpp

${OBJECTDIR}/_ext/533720680/MenuState.o: ../SpaceRace/GameState/MenuState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/533720680
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/533720680/MenuState.o ../SpaceRace/GameState/MenuState.cpp

${OBJECTDIR}/_ext/533720680/PauseState.o: ../SpaceRace/GameState/PauseState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/533720680
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/533720680/PauseState.o ../SpaceRace/GameState/PauseState.cpp

${OBJECTDIR}/_ext/533720680/RaceState.o: ../SpaceRace/GameState/RaceState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/533720680
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/533720680/RaceState.o ../SpaceRace/GameState/RaceState.cpp

${OBJECTDIR}/_ext/991262536/Random.o: ../SpaceRace/Random.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/991262536
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/991262536/Random.o ../SpaceRace/Random.cpp

${OBJECTDIR}/_ext/694709887/BasicSpawner.o: ../SpaceRace/Spawner/BasicSpawner.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/694709887
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/694709887/BasicSpawner.o ../SpaceRace/Spawner/BasicSpawner.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/include -IContentManager -IGameState -IEntity -I. -ICollider -ISpawner -IBackground -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../../bin/${CND_CONF}/SpaceRace.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
