# Variáveis de compilador e flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall

# Diretivas de arquivos
TARGET = main
OBJECTS = main.o produto.o 
HEADERS = produto.h 

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regras para gerar arquivos .o a partir dos .cpp
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

produto.o: produto.cpp produto.h
	$(CXX) $(CXXFLAGS) -c produto.cpp

# Limpeza dos arquivos temporários
clean:
	rm -f $(TARGET) $(OBJECTS)

# Limpeza total, incluindo os arquivos de backup
cleanall: clean
	rm -f *~
