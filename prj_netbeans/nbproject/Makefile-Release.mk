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
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1360937237/Transform.o \
	${OBJECTDIR}/_ext/1360937237/Main.o \
	${OBJECTDIR}/_ext/1360937237/Group.o \
	${OBJECTDIR}/_ext/1360937237/Camera.o \
	${OBJECTDIR}/_ext/1360937237/Mesh.o \
	${OBJECTDIR}/_ext/1360937237/Material.o \
	${OBJECTDIR}/_ext/1360937237/manipulator.o \
	${OBJECTDIR}/_ext/1360937237/Light.o \
	${OBJECTDIR}/_ext/1360937237/Scene.o \
	${OBJECTDIR}/_ext/1360937237/Cube.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/prj_netbeans

dist/Release/GNU-Linux-x86/prj_netbeans: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prj_netbeans ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1360937237/Transform.o: ../src/Transform.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Transform.o ../src/Transform.cpp

${OBJECTDIR}/_ext/1360937237/Main.o: ../src/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Main.o ../src/Main.cpp

${OBJECTDIR}/_ext/1360937237/Group.o: ../src/Group.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Group.o ../src/Group.cpp

${OBJECTDIR}/_ext/1360937237/Camera.o: ../src/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Camera.o ../src/Camera.cpp

${OBJECTDIR}/_ext/1360937237/Mesh.o: ../src/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Mesh.o ../src/Mesh.cpp

${OBJECTDIR}/_ext/1360937237/Material.o: ../src/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Material.o ../src/Material.cpp

${OBJECTDIR}/_ext/1360937237/manipulator.o: ../src/manipulator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/manipulator.o ../src/manipulator.cpp

${OBJECTDIR}/_ext/1360937237/Light.o: ../src/Light.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Light.o ../src/Light.cpp

${OBJECTDIR}/_ext/1360937237/Scene.o: ../src/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Scene.o ../src/Scene.cpp

${OBJECTDIR}/_ext/1360937237/Cube.o: ../src/Cube.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/Cube.o ../src/Cube.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/prj_netbeans

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
