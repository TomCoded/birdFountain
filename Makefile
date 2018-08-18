MAKE=make

# directories containing classes: class name equals directory name!
ALLCLASSDIRS = Camera Ray TransformMaker NodeGL \
PopNodeGL MaterialNodeGL TranslationFormNodeGL Scene functions \
LightNodeGL PlanetNodeGL TransformNodeGL OrbitNodeGL \
SpinNodeGL OrientNodeGL TorusNodeGL TeapotNodeGL \
CubeNodeGL IcosahedronNodeGL OctahedronNodeGL \
TetrahedronNodeGL DodecahedronNodeGL ConeNodeGL \
RotateNodeGL SinTranslateNodeGL SinSpinNodeGL \
CustomNodeGL \
FunNode VarFunNode SumFunNode MultFunNode DivFunNode \
PowFunNode SinFunNode CosFunNode FunParser \
FunTranslateNodeGL FunOrientNodeGL \
FunTransformNodeGL

# directories containing programs: prog name equals directory name!
ALLPROGDIRS = SceneTest

birdFountain: allClassObjs
	cd Scene && $(MAKE) SceneTest
	cd ..

# rule to compile all class.o object files
allClassObjs :
	for x in $(ALLCLASSDIRS); do \
		$(MAKE) -C $$x $$x.o; \
	done

# rule to compile all classTest programs
allClassTests :
	for x in $(ALLCLASSDIRS); do \
		$(MAKE) -C $$x $${x}Test; \
	done

# rule to compile all programs
allProgs : 
	for x in $(ALLPROGDIRS); do \
		$(MAKE) -C $$x $$x; \
	done

# do it all!
all : allProgs allClassObjs allClassTests

# clean-up rules
clean :
	for x in $(ALLPROGDIRS) $(ALLCLASSDIRS); do \
		$(MAKE) -C $$x clean; \
	done

veryclean :
	for x in $(ALLPROGDIRS) $(ALLCLASSDIRS); do \
		$(MAKE) -C $$x veryclean; \
	done

strip :
	for x in $(ALLPROGDIRS) $(ALLCLASSDIRS); do \
		$(MAKE) -C $$x strip; \
	done

# tell make that the targets above are not real files
.PHONY : $(ALLCLASSDIRS) $(ALLPROGDIRS) allClassTests allClassObjs
.PHONY : allProgs all clean veryclean strip
