# @desc makefile for Server
# @author viticm<viticm.ti@gmail.com>
# @date 2013-07-08 14:10:35
include ../../../../premake.mk

CFLAGS  = -I$(BASEDIR)/Server/EventModule -I$(BASEDIR)/Server/Item -I$(BASEDIR)/Server/Script -I$(BASEDIR)/Server/Main -I$(BASEDIR)/Server/Obj -I$(BASEDIR)/Server/Team -I$(BASEDIR)/Server/DB -I$(BASEDIR)/Server/MenPai -I$(BASEDIR)/Server/Packets -I$(BASEDIR)/Server/AI -I$(BASEDIR)/Server/Player -I$(BASEDIR)/Server/ActionModule -I$(BASEDIR)/Server/Skills -I$(BASEDIR)/Server/Skills/SpecialObjLogic -I$(BASEDIR)/Server/Skills/SkillLogic -I$(BASEDIR)/Server/Skills/SkillLogic/Item -I$(BASEDIR)/Server/Skills/SkillLogic/Common -I$(BASEDIR)/Server/Skills/SkillLogic/Human -I$(BASEDIR)/Server/Skills/SkillLogic/Pet -I$(BASEDIR)/Server/Skills/ImpactLogic -I$(BASEDIR)/Server/Mission -I$(BASEDIR)/Server/Ability -I$(BASEDIR)/Server/Other -I$(BASEDIR)/Server/Scene -I$(BASEDIR)/Server/Scene/Scan -I$(BASEDIR)/Server/SMU -I$(BASEDIR)/Server/Base -I$(BASEDIR)/Server $(LUA_INCLUDES)
LDFLAGS =
DIRS =  
OBJS =  DaLiSkill007.o \
		XiaoYaoSkill016.o \
		TianShanSkill010.o \
		DaLiSkill001.o \
		XiaoYaoSkill001.o \
		XiaoYaoSkill002.o \
		GaiBangSkill001.o \
		TianShanSkill009.o \
		MingJiaoSkill002.o \
		ShaoLinSKill002.o \
		GaiBangSkill014.o \
		GaiBangSkill002.o \
		DaLiSkill014.o \
		GaiBangSkill004.o \
		XingXiuSkill008.o \
		EMeiSkill001.o \
		ShaoLinSKill007.o \
		MingJiaoSkill001.o \
		TianShanSkill001.o \
		TianShanSkill013.o \
		WuDangSkill001.o

debug:$(OBJS)
	for dir in $(DIRS); do \
		$(MAKE) debug -C $$dir; \
	done

release:$(OBJS)
	for dir in $(DIRS); do \
		$(MAKE) release -C $$dir; \
	done

all:debug

clean:
	$(RM) -f *.o
