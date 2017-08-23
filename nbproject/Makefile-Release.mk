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
CND_PLATFORM=Cygwin-Windows
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
	${OBJECTDIR}/GeneralMovement.o \
	${OBJECTDIR}/OsuFileParser.o \
	${OBJECTDIR}/OsuMovement.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/parser/Circle.o \
	${OBJECTDIR}/parser/HitObject.o \
	${OBJECTDIR}/parser/Spinner.o \
	${OBJECTDIR}/parser/TimingPoint.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/myosuauto.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/myosuauto.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/myosuauto ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/GeneralMovement.o: GeneralMovement.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GeneralMovement.o GeneralMovement.cpp

${OBJECTDIR}/OsuFileParser.o: OsuFileParser.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OsuFileParser.o OsuFileParser.cpp

${OBJECTDIR}/OsuMovement.o: OsuMovement.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OsuMovement.o OsuMovement.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/parser/Circle.o: parser/Circle.cpp
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/Circle.o parser/Circle.cpp

${OBJECTDIR}/parser/HitObject.o: parser/HitObject.cpp
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/HitObject.o parser/HitObject.cpp

${OBJECTDIR}/parser/Spinner.o: parser/Spinner.cpp
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/Spinner.o parser/Spinner.cpp

${OBJECTDIR}/parser/TimingPoint.o: parser/TimingPoint.cpp
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/TimingPoint.o parser/TimingPoint.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
