default:
	rm -rf *.o
a.out: teacher.o client.o course.o read.o generate.o TeacherConst.o CourseConst.o
	g++ teacher.o client.o course.o read.o generate.o TeacherConst.o CourseConst.o
course.o: course.cpp
	g++ -c course.cpp
client.o: client.cpp
	g++ -c client.cpp
teacher.o:teacher.cpp 
	g++ -c teacher.cpp 
read.o:read.cpp
	g++ -c read.cpp
generate.o:generate.cpp
	g++ -c generate.cpp
TeacherConst.o:TeacherConst.cpp
	g++ -c TeacherConst.cpp
CourseConst.o:CourseConst.cpp
	g++ -c CourseConst.cpp
