# Nome do executável final
TARGET = bst

# Diretórios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I$(INC_DIR)

# Arquivos fonte e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Regra principal
all: $(TARGET)

# Compila o executável
$(TARGET): $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o $(TARGET)

# Compila os arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria o diretório obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpeza dos arquivos objetos e executável
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
