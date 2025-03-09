# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp \
       FormeGeometrique.cpp \
       FormeGeometriqueSimple.cpp \
       Groupe.cpp \
       LoadHandler.cpp \
       SaveVisitor.cpp \
       SimpleShapeLoadHandler.cpp \
       TCPClient.cpp \
       TCPVisitor.cpp \
       WinsockInitializer.cpp

# Header files
HDRS = FormeGeometrique.h \
       FormeGeometriqueSimple.h \
       Groupe.h \
       LoadHandler.h \
       SaveVisitor.h \
       SimpleShapeLoadHandler.h \
       TCPClient.h \
       TCPVisitor.h \
       Visitor.h \
       WinsockInitializer.h

# Output executable
TARGET = projet_PPIL

# Build target
$(TARGET): $(SRCS) $(HDRS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean target
clean:
    rm -f $(TARGET)