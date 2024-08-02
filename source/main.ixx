export module stk.main;

import stk.log;
import <vector>;
import <fstream>;
import <nlohmann/json.hpp>;

namespace stk
{
	export class c_main
	{
	public:
		c_main()
		{
			logln("main ran successfully");
			read_json_data();
		}

	private:
		void read_json_data()
		{
			std::ifstream file("data/data.json");
			if (!file.is_open())
			{
				errorln("Failed to open data.json");
				return;
			}

			nlohmann::json json_data;
			file >> json_data;

			for (const auto& item : json_data)
			{
				if (item["type"] == "Test")
				{
					std::vector<int> data = item["data"].get<std::vector<int>>();
					if (data.size() == 0)
					{
						continue;
					}
					logln("Test data:");
					for (auto datum : data)
					{
						logln("    {}", datum);
					}
				}
			}
		}
	};
}