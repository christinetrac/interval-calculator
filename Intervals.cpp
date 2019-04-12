#include <iostream>
#include <string>

int main();

void interval_calculator();

int main() {
	interval_calculator();
	return 0;
}

void interval_calculator(){
	std::string command{};

	double a{};
	double b{};

	double immediate_a{};
	double immediate_b{};

	double memory_a{};
	double memory_b{};

	double store_a{};
	double store_b{};

	bool is_initialized{};
	bool has_memory{};

	while(command != "exit"){

		//asking for the command
		std::cout << "input :> ";
		std::cin >> command;

		//enter command *
		if(command == "enter"){
			std::cin >> a >> b;
			if(a > b){
				std::cout << "Error: invalid interval as " << a << " > " << b << std::endl;
				std::cout << "--" << std::endl;
			} else {
				immediate_a = a;
				immediate_b = b;
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				is_initialized = true;
				}
		}
		else{
		}

		//negate command *
		if(command == "negate"){
			if(is_initialized == true){
				std::cout << "[" << -(immediate_b) << ", " << -(immediate_a) << "]" << std::endl;
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//invert command *
		else if(command == "invert"){
			if(is_initialized == true){
				if((immediate_a <= 0)&&(immediate_b >= 0)){
					std::cout << "Error: division by zero" << std::endl;
					std::cout << "--" << std::endl;
					is_initialized = false;
				}
				else {
					std::cout << "[" << 1/immediate_b << ", " << 1/immediate_a << "]" << std::endl;
				}
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//ms command *
		else if(command == "ms"){
			if(is_initialized == true){
				memory_a = immediate_a;
				memory_b = immediate_b;
				store_a = memory_a;
				store_b = memory_b;
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				has_memory = true;
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//mr command *
		else if(command == "mr"){ //need to fix lol
			if(is_initialized == true && has_memory == true){
				immediate_a = store_a;
				immediate_b = store_b;
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
			else if(is_initialized == true){
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//mc command *
		else if(command == "mc"){
			if(is_initialized == true){
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				has_memory = false;
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//m+ command *
		else if(command == "m+"){
			if(is_initialized == true && has_memory == true){
				memory_a += immediate_a;
				memory_b += immediate_b;
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
			else if(is_initialized == true){
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//m- command *
		else if(command == "m-"){
			if(is_initialized == true && has_memory == true){
				memory_a -= immediate_a;
				memory_b -= immediate_b;
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
			else if(is_initialized == true || has_memory == true){
				std::cout << "--" << std::endl;
			}
			else{
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
		}

		// scalar add command *
		else if(command == "scalar_add"){
			double c{};
			std::cin >> c;
			if(is_initialized == true){
				immediate_a += c;
				immediate_b += c;
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//scalar subtract command *
		else if(command == "scalar_subtract"){
			double c{};
			std::cin >> c;
			if(is_initialized == true){
				immediate_a -= c;
				immediate_b -= c;
				std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//scalar multiply command *
		else if(command == "scalar_multiply"){
			double c{};
			std::cin >> c;
			if(is_initialized == true){
				if(c>0){
					immediate_a *= c;
					immediate_b *= c;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else if(c<0){
					immediate_a *= c;
					immediate_b *= c;
					std::cout << "[" << immediate_b << ", " << immediate_a << "]" << std::endl;
				}
				else{
					std::cout << "[0, 0]" << std::endl;
				}
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//scalar divide command * value for immediate_a
		else if(command == "scalar_divide"){
			double c{};
			std::cin >> c;
			if(is_initialized == true){
				if(c>0){
					immediate_a = immediate_a/c;
					immediate_b = immediate_b/c;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else if(c<0){
					immediate_a = immediate_b/c;
					immediate_b = immediate_a/c;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else{
					std::cout << "Error: division by zero" << std::endl;
					is_initialized = false;
					std::cout << "--" << std::endl;
				}
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//scalar divided by command
		else if(command == "scalar_divided_by"){
			double c{};
			std::cin >> c;
			if(is_initialized == true){
				if((immediate_a  <= 0) && (immediate_b >= 0)){
					std::cout << "Error: division by zero" << std::endl;
					is_initialized = false;
				}
				else{
					if(c>0){
						immediate_a = c/immediate_b;
						immediate_b = c/immediate_a;
						std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
					}
					else{
						immediate_a = c/immediate_a;
						immediate_b = c/immediate_b;
						std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
					}
				}
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//interval add command
		else if(command == "interval_add"){
			double c{};
			double d{};
			std::cin >> c >> d;
			if(is_initialized == true){
				if(c>d){
					std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else{
					std::cout << "[" << immediate_a + c << ", " << immediate_b + d << "]" << std::endl;
				}
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//interval subtract command *
		else if(command == "interval_subtract"){
			double c{};
			double d{};
			std::cin >> c >> d;
			if(is_initialized == true){
				if(c>d){
					std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else{
					std::cout << "[" << immediate_a - d << ", " << immediate_b - c << "]" << std::endl;
				}
			}
			else{
				std::cout << "--" << std::endl;
			}
		}

		//interval multiply command
		else if(command == "interval_multiply"){
			double c{};
			double d{};
			std::cin >> c >> d;
			if(c>d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				if(is_initialized == true){
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else{
					std::cout << "--" << std::endl;
				}
			}
			else{
				if(is_initialized == true){
					double max{};
					double min{};
					double ac = c*immediate_a;
					double ad = d*immediate_a;
					double bc = c*immediate_b;
					double bd = d*immediate_b;

					if(ac>ad && ac>bc && ac>bd){
						max = ac;
					}
					else if(ad>ac && ad>bc && ad>bd){
						max = ad;
					}
					else if(bc>bd && bc>ac && bc>ad){
						max = bc;
					}
					else{
						max = bd;
					}

					if(ac<ad && ac<bc && ac<bd){
						min = ac;
					}
					else if(ad<ac && ad<bc && ad<bd){
						min = ad;
					}
					else if(bc<bd && bc<ac && bc<ad){
						min = bc;
					}
					else{
						min = bd;
					}
					std::cout << "[" << min << ", " << max << "]" << std::endl;
				}
				else{
					std::cout << "--" << std::endl;
				}
			}
		}

		//interval divide command*
		else if(command == "interval_divide"){
			double c{};
			double d{};
			std::cin >> c >> d;
			if(c>d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				if(is_initialized == true){
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else{
					std::cout << "--" << std::endl;
				}
			} else if(c<=0 && d>=0) {
				std::cout << "Error: division by zero" << std::endl;
				std::cout << "--" << std::endl;
				is_initialized = false;
			}
			else{
				if(is_initialized == true){
					double max{};
					double min{};
					double ac = immediate_a/c;
					double ad = immediate_a/d;
					double bc = immediate_b/c;
					double bd = immediate_b/d;

					if(ac>ad && ac>bc && ac>bd){
						max = ac;
					}
					else if(ad>ac && ad>bc && ad>bd){
						max = ad;
					}
					else if(bc>bd && bc>ac && bc>ad){
						max = bc;
					}
					else{
						max = bd;
					}

					if(ac<ad && ac<bc && ac<bd){
						min = ac;
					}
					else if(ad<ac && ad<bc && ad<bd){
						min = ad;
					}
					else if(bc<bd && bc<ac && bc<ad){
						min = bc;
					}
					else{
						min = bd;
					}
					std::cout << "[" << min << ", " << max << "]" << std::endl;
				}
				else{
					std::cout << "--" << std::endl;
				}
			}
		}

		//insersect command
		else if(command == "intersect"){
			double c{};
			double d{};
			std::cin >> c >> d;
			if(c>d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				if(is_initialized == false){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
			}
			else if(is_initialized == false){
				std::cout << "--" << std::endl;
			}
			else{
				if((immediate_a>=c && immediate_a<=d) && (immediate_b>=c && immediate_b<=d)){
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else if ((c>=immediate_a && c<=immediate_b) && (d>=immediate_a && d<=immediate_b)){
					immediate_a = c;
					immediate_b = d;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else if(immediate_a>=c && immediate_a<=d){
					immediate_b = d;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else if(immediate_b>=c && immediate_b<=d){
					immediate_a = c;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else if(c>=immediate_a && c<=immediate_b){
					immediate_a = c;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else if(d>=immediate_a && d<=immediate_b){
					immediate_b = d;
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else{
					is_initialized = false;
					std::cout << "--" << std::endl;
				}
			}
		}

		 else if(command == "integers"){
			 int int_a = immediate_a;
			 int int_b = immediate_b;
			 if(is_initialized == false){
				 std::cout << "--" << std::endl;
			 }
			 else{
				 if((immediate_a - int_a) >= 0.5){
					 int_a++;
				 }
				 if((immediate_b - int_b) >= 0.5){
					 int_b++;
				 }
			 	 while(int_a < int_b-1){
					 		std::cout << int_a << ", ";
					 		int_a++;
			 	 }

			 	 if((immediate_b - immediate_a) <= 1){
			 		 std::cout << int_b << std::endl;
			 	 }
			 	 else{
			 		 std::cout << int_b-1 << std::endl;
			 	 }
			 	 std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
			 }
		 }

		//cartesian integers command NEED TO FIX i tried to fix it
		else if(command == "cartesian_integers"){
			double c{};
			double d{};
			std::cin >> c >> d;
			if(is_initialized == false){
				std::cout << "--" << std::endl;
			}
			else if(c>d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				if(is_initialized == false){
					std::cout << "--" << std::endl;
				}
				else{
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
			}
			else{
				int int_a = immediate_a;
				int int_b = immediate_b;
				int int_c = c;
				int int_d = d;

				 if((immediate_a - int_a) >= 0.5){
					 int_a++;
				 }
				 if((immediate_b - int_b) >= 0.5){
					 int_b++;
				 }
				 if((c - int_c) >= 0.5){
					 int_c++;
				 }
				 if((d - int_d) >= 0.5){
					 int_d++;
				 }

				if(c!=d && int_c==int_d){
					std::cout << "[" << immediate_a << ", " << immediate_b << "]" << std::endl;
				}
				else{
					std::cout << "(" << int_a << "," << int_c << "),";
					std::cout << " (" << int_a << "," << int_d << "),";
					std::cout << " (" << int_b << "," << int_c << "),";
					std::cout << " (" << int_b << "," << int_d << ")" << std::endl;
				}
			}
		}

		//exit command *
		else if(command == "exit"){
			std::cout << "Bye bye: Terminating interval calculator program.";
		}

		//when input is not a command *
		else if(command != "enter"){
			std::cout << "Error: illegal command" << std::endl;
		}
	}
}




