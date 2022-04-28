#
#Makefile for cbhproj
#
CC=g++
CFLAGS= 
OBJ= UserWait.o cbhproj.o PrintHdMenu.o State.o Option1.o Option2.o Option3.o Option4.o Option5.o Option6.o Option7.o Color.o\
 County.o Vtype.o Vmake.o Person.o PersonFile.o Vehicle.o VehicleFile.o SSNHyphens.o SSNNoHyphens.o Upper.o ZipHyphens.o ZipNoHyphens.o Trim.o\

cbhproj: $(OBJ)
	$(CC) -o cbhproj $(OBJ)

UserWait.o: UserWait.cpp
	$(CC) $(CFLAGS) -c UserWait.cpp

cbhproj.o: cbhproj.cpp
	$(CC) $(CFLAGS) -c cbhproj.cpp

PrintHdMenu.o: PrintHdMenu.cpp
	$(CC) $(CFLAGS) -c PrintHdMenu.cpp

State.o: State.cpp
	$(CC) $(CFLAGS) -c State.cpp

Option1.o: Option1.cpp
	$(CC) $(CFLAGS) -c Option1.cpp

Option2.o: Option2.cpp
	$(CC) $(CFLAGS) -c Option2.cpp

Option3.o: Option3.cpp
	$(CC) $(CFLAGS) -c Option3.cpp

Option4.o: Option4.cpp
	$(CC) $(CFLAGS) -c Option4.cpp

Option5.o: Option5.cpp
	$(CC) $(CFLAGS) -c Option5.cpp

Option6.o: Option6.cpp
	$(CC) $(CFLAGS) -c Option6.cpp

Option7.o: Option7.cpp
	$(CC) $(CFLAGS) -c Option7.cpp

Color.o: Color.cpp
	$(CC) $(CFLAGS) -c Color.cpp

County.o: County.cpp
	$(CC) $(CFLAGS) -c County.cpp

Vtype.o: Vtype.cpp
	$(CC) $(CFLAGS) -c Vtype.cpp

Vmake.o: Vmake.cpp
	$(CC) $(CFLAGS) -c Vmake.cpp

Person.o: Person.cpp
	$(CC) $(CFLAGS) -c Person.cpp

Vehicle.o: Vehicle.cpp
	$(CC) $(CFLAGS) -c Vehicle.cpp

PersonFile.o: PersonFile.cpp
	$(CC) $(CFLAGS) -c PersonFile.cpp

VehicleFile.o: VehicleFile.cpp
	$(CC) $(CFLAGS) -c VehicleFile.cpp

SSNHyphens.o: SSNHyphens.cpp
	$(CC) $(CFLAGS) -c SSNHyphens.cpp

SSNNoHyphens.o: SSNNoHyphens.cpp
	$(CC) $(CFLAGS) -c SSNNoHyphens.cpp

Upper.o: Upper.cpp
	$(CC) $(CFLAGS) -c Upper.cpp

ZipHyphens.o: ZipHyphens.cpp
	$(CC) $(CFLAGS) -c ZipHyphens.cpp

ZipNoHyphens.o: ZipNoHyphens.cpp
	$(CC) $(CFLAGS) -c ZipNoHyphens.cpp

Trim.o: Trim.cpp
	$(CC) $(CFLAGS) -c Trim.cpp

clean:
	rm cbhproj *.o *.db core jscarrasquilla.tar jscarrasquilla.tar.gz
