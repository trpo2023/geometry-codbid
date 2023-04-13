CC = gcc
CFLAGS = -Wall -Werror -Isrc/libgeometry -MMD
TARGET = bin/geometry
OBJDIR = obj
SRCDIR = src

SRC_GEOMETRY_DIR = $(SRCDIR)/geometry
SRC_LIBGEOMETRY_DIR = $(SRCDIR)/libgeometry
OBJ_GEOMETRY_DIR = $(OBJDIR)/geometry
OBJ_LIBGEOMETRY_DIR = $(OBJDIR)/libgeometry

SRC_GEOMETRY = $(wildcard $(SRC_GEOMETRY_DIR)/*.c)
OBJ_GEOMETRY = $(patsubst $(SRC_GEOMETRY_DIR)/%.c, $(OBJ_GEOMETRY_DIR)/%.o, $(SRC_GEOMETRY))
DEP_GEOMETRY = $(OBJ_GEOMETRY:.o=.d)

SRC_LIBGEOMETRY = $(wildcard $(SRC_LIBGEOMETRY_DIR)/*.c)
OBJ_LIBGEOMETRY = $(patsubst $(SRC_LIBGEOMETRY_DIR)/%.c, $(OBJ_LIBGEOMETRY_DIR)/%.o, $(SRC_LIBGEOMETRY))
DEP_LIBGEOMETRY = $(OBJ_LIBGEOMETRY:.o=.d)

GEOOBJS = $(OBJ_GEOMETRY_DIR)/main.o
LIBOBJS = $(OBJ_LIBGEOMETRY_DIR)/parser.o
LIBNAME = $(OBJ_LIBGEOMETRY_DIR)/libgeometry.a

.PHONY: all clean clean_all

all: $(TARGET)

$(TARGET): $(GEOOBJS) $(LIBNAME)
	$(CC) $^ -o $@

$(OBJ_GEOMETRY_DIR)/%.o: $(SRC_GEOMETRY_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_LIBGEOMETRY_DIR)/%.o: $(SRC_LIBGEOMETRY_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBNAME): $(LIBOBJS)
	ar rcs $@ $^

-include $(DEP_GEOMETRY)
-include $(DEP_LIBGEOMETRY)

clean:
	$(RM) -r $(OBJ_GEOMETRY_DIR)/* $(OBJ_LIBGEOMETRY_DIR)/* $(LIBNAME)

clean_all:
	$(RM) -r $(OBJ_GEOMETRY_DIR)/* $(OBJ_LIBGEOMETRY_DIR)/* $(TARGET) $(LIBNAME)
