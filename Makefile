#
# double_md5_hash_table
#
# Makefile: 
#

TARGET = test_program
test_program_OBJECTS=test_program.o
test_program_SOURCES=$(test_program_OBJECTS:.o=.c)
libobj=dmht.o

.PHONY=all clean

CFLAGS += -g -fopenmp 
LDFLAGS += 
#LDADD += -L/usr/lib/x86_64-linux-gnu/ -lcrypto
LDADD +=  -lcrypto

all: $(TARGET)

$(TARGET): $(test_program_OBJECTS) $(libobj)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDADD)

clean:
	-rm *.o $(TARGET)


