#
# double_md5_hash_table
#
# Makefile: 
#

TARGET = test_program
TARGET2 = double_test
test_program_OBJECTS=test_program.o
test_program_SOURCES=$(test_program_OBJECTS:.o=.c)
double_test_OBJECTS=double_test.o
double_test_SOURCES=$(double_test_OBJECTS:.o=.c)
libobj=dmht.o

.PHONY=all clean

CFLAGS += -g -fopenmp 
LDFLAGS += 
#LDADD += -L/usr/lib/x86_64-linux-gnu/ -lcrypto
LDADD +=  -lcrypto

all: $(TARGET) $(TARGET2)

$(TARGET): $(test_program_OBJECTS) $(libobj)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDADD)

$(TARGET2): $(double_test_OBJECTS) $(libobj)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDADD)

clean:
	-rm *.o $(TARGET)


