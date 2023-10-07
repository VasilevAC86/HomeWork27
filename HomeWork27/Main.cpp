# include <iostream>
#include <string>

struct Movie { // Описание структуры
	std::string title = "empty";
	unsigned int year = 1970;
	std::string genre = "drama";
	unsigned int duration = 100;
	unsigned int price = 250;
};

// Блок прототипов функций
void print_Movie(const Movie& m, short arr[], const short size, short row); // Процедура вывода в таблицу информации об объекте структуры
short table_Widht(std::string arr[], std::string header, const short size); // Функция расчёта ширины столбца таблицы (по длине самой длинной строки массива)
void table_Cell(std::string header, short widht); // Процедура заполнения ячейки таблицы
Movie expensive(Movie arr[], const short size); // Функция поиска самого дорогого фильма
short exam_Value(short value, short start, short end); // Функция проверки значения value в диапазоне от start до end включительно
void update_Info(Movie& m); // Процедура изменения информации в объекте структуры

short index; // Глобальная переменная для хранения номера объекта структуры

int main() {
	std::cout << "\033[91mHome work on the topic \"Struct\".\033[0m\n\n\033[93mSourse movie table:\033[0m\n";
	// Инициализация структуры
	Movie m1{ "Bloodsport", 1988, "Martial arts action", 92 }, 
		m2{"The Matrix", 1999, "Science fiction action", 136, 500},
		m3{"Inception", 2010, "Science fiction action", 148, 725},
		m4{"Text", 2019, "Crime drama", 132, 640},
		m5{"Crazy wedding", 2014, "Comedy", 97, 800};
	const short number_Movies = 5; // Размер массива с фильмами (количество фильмов)
	const short number_Columns = 6; // Размер массива с параметрами фильмов (параметр N 6 - это порядковый номер фильма в таблице)
	short volum_Width[number_Columns]; // Массив для хранения значений ширины для каждого из столбцов таблицы фильмов			 			
	char my_Choise; // Переменная для хранения выбора пользователя		 
	do { // Цикл изменения таблицы фильмов и поиска самого дорого фильма в завимости от действий пользователя		
		index = 1;
		std::string title_Movies[number_Movies]{ m1.title,m2.title,m3.title,m4.title,m5.title }; // Массив для хранения названий фильмов
		std::string genre_Movies[number_Movies]{ m1.genre,m2.genre,m3.genre,m4.genre,m5.genre }; // Массив для хранения жанра фильмов	
		// Массив для хранения стоимости фильмов в формате типа данных string (для корректной работы функции table_Widht и table_Cell)
		std::string price_Movies[number_Movies]{ std::to_string(m1.price),std::to_string(m2.price),std::to_string(m3.price),std::to_string(m4.price),std::to_string(m5.price) };
		// Объявляем и инициализируем массив типа данных Movie для хранения объектов структуры Movie	
		Movie array_Movie[number_Movies]{ m1,m2,m3,m4,m5 };
		for (short i = 0; i < number_Movies + 1; i++) { // +1 к кол-ву фильмов - это верхняя строка таблицы с заголовками столбцов
			for (short j = 0; j < number_Columns; j++) { // Вложенный цикл заполнения заголовков столбцов таблицы
				if (i == 0) { // Конструкция для формирования столбцов (размеры столбцов, их заголовки)
					if (j == 0) {
						volum_Width[j] = 3; // Ширина столбца "N" таблицы (количество фильмов константа и не будет больше дины одного символа)
						std::cout << "  \033[92mN\033[0m  |";
					}
					if (j == 1) { // Определяем ширину колонки таблицы с названием фильма = ширине самой длиной строки
						volum_Width[j] = table_Widht(title_Movies, "The title of the movie", number_Movies);
						std::cout << "\033[92m";
						table_Cell("The title of the movie", volum_Width[j]);
					}
					if (j == 2) {
						volum_Width[j] = 4; // Ширина столбца "Year" таблицы (год - это по-любому четырёхзначное число);
						std::cout << " \033[92mYear\033[0m |";
					}
					if (j == 3) { // Определяем ширину колонки с жанром фильма = ширине самой длинной строки
						volum_Width[j] = table_Widht(genre_Movies, "Genre", number_Movies);
						std::cout << "\033[92m";
						table_Cell("Genre", volum_Width[j]);
					}
					if (j == 4) {
						volum_Width[j] = 13; // Ширина столбца продолжительности фильма в минутах = кол-ву символов в строке "Duration, min" 
						std::cout << " \033[92mDuration, min\033[0m |";
					}
					if (j == 5) { // Определяем ширину колонки с ценой фильма фильма = ширине самой длинной строки (цена переведена в строковой тип данных)
						volum_Width[j] = table_Widht(price_Movies, "Price, rub", number_Movies);
						std::cout << "\033[92m";
						table_Cell("Price, rub", volum_Width[j]);
					}
				}
			}
			short size_Table = 0; // Переменная для определения ширины всей таблицы фильмов в символах 
			for (short j = 0; j < number_Columns; j++) { // Вложенный цикл расчёта ширины всей таблицы в символах
				for (short k = 0; k < volum_Width[j]; k++)
					size_Table++;
				size_Table += 3; // Каждый j-ый столбец больше расчётной ширины vilum_Width[j] на 3 символа (отступы перед и после строки + символ "|")
			}
			if (i) { // Конструкция для разлиновки строк				
				std::cout << std::endl;
				for (short j = 0; j < size_Table; j++)
					std::cout << '-';
			}
			// Далее идут конструкции для заполнения таблицы фильмов данными объектов из структуры Movie
			if (i == 1)
				print_Movie(m1, volum_Width, number_Columns, i);
			if (i == 2)
				print_Movie(m2, volum_Width, number_Columns, i);
			if (i == 3)
				print_Movie(m3, volum_Width, number_Columns, i);
			if (i == 4)
				print_Movie(m4, volum_Width, number_Columns, i);
			if (i == 5)
				print_Movie(m5, volum_Width, number_Columns, i);
		}
		std::cout << "\n\n";		
		std::cout << "\033[92mThe most expensive movie is: \033[0m";		
		print_Movie(expensive(array_Movie, number_Movies), volum_Width, number_Columns, index);
		std::cout << std::endl << std::endl << "\033[93mDo want to update some information in the movie table?\nPress '1' to YES \033[91mor\033[0m\033[93m press any other key to NO\nYour choise\033[0m -> ";
		std::cin >> my_Choise;
		if (my_Choise == '1') {
			std::cout << "Select the sequence number of the movie from the movie table -> ";
			short movie_Number; // Переменная для хранения порядкового номера фильма
			std::cin >> movie_Number;
			movie_Number = exam_Value(movie_Number, 1, number_Movies);			
			switch (movie_Number) {
			case 1:
				update_Info(m1);				
				break;
			case 2:
				update_Info(m2);				
				break;
			case 3:
				update_Info(m3);				
				break;
			case 4:
				update_Info(m4);				
				break;
			case 5:
				update_Info(m5);				
			}
		}		
		std::cout << std::endl << std::endl;
	} while (my_Choise == '1');	

	return 0;
}

short table_Widht(std::string arr[], std::string header, const short size) {
	short max = header.length();
	for (short i = 0; i < size; i++)
		max = max > arr[i].length() ? max : arr[i].length();
	return max;
}

void table_Cell(std::string header, short widht) {
	short length = widht - header.length(); // Кол-во символов "пустоты", не занятых строкой "header"	
	for (short i = 0; i <= length / 2; i++)
		std::cout << ' ';
	std::cout << header;
	for (short i = 0; i <= length - length / 2; i++)
		std::cout << ' ';
	std::cout << "\033[0m|";
}

void print_Movie(const Movie& m, short arr[], const short size, short row) {
	for (short i = 0; i < size; i++) {
		if (i == 0) {
			std::cout << std::endl;
			table_Cell(std::to_string(row), arr[i]);
		}
		if (i == 1)
			table_Cell(m.title, arr[i]);
		if (i == 2)
			table_Cell(std::to_string(m.year), arr[i]);
		if (i == 3)
			table_Cell(m.genre, arr[i]);
		if (i == 4)
			table_Cell(std::to_string(m.duration), arr[i]);
		if (i == 5)
			table_Cell(std::to_string(m.price), arr[i]);
	}		
}

Movie expensive(Movie arr[], const short size) {		
	int max = arr[0].price;
	for (short i = 1; i < size; i++)
		if (arr[i].price > max) {
			max = arr[i].price;
			index = i + 1; // Номер объекта структуры начинается с 1, а индекс массива с 0
		}
	return arr[index - 1]; // Учитываем разницу индексации объектов структуры и элементов массива
}

short exam_Value(short value, short start, short end) {
	while (value < start || value > end) {
		std::cout << "Input error! The entered value must be in the range from" << start << " to " << end << " inclusive!\nEnter the value one more time -> ";
		std::cin >> value;
	}
	return value;
}

void update_Info(Movie& m) {
	std::cout << "Select the information whitch you want to update:\n1. Title;\n2. Year;\n3. Genre;\n4. Duration;\n5. Price\nChoose the position -> ";
	short position; // Локальная переменная для хранения выбранной пользователем позиции
	std::cin >> position;
	position = exam_Value(position, 1, 5);	
	std::cin.ignore();
	switch (position) {
	case 1:
		std::cout << "Update the title of the movie -> ";
		std::getline(std::cin, m.title);
		break;
	case 2:
		std::cout << "Update the release year of the movie -> ";
		std::cin >> m.year;
		break;
	case 3:
		std::cout << "Update the genre of the movie -> ";
		std::getline(std::cin, m.genre);
		break;
	case 4:
		std::cout << "Update the durartion of the movie -> ";
		std::cin >> m.duration;
		break;
	case 5:
		std::cout << "Update the price of the movie -> ";
		std::cin >> m.price;
	}
	std::cout << "The data was update";
}
