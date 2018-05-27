#pragma once
#include <vector>

struct ImportItem {
	bool custom = false;
	fs::path name;
	int size;
	fs::path full_path;

	std::vector<ImportItem> children;
};

class Imports {
public:
	//std::vector<ImportItem> war3map_imp;
	std::vector<ImportItem> uncategorized;
	std::vector<ImportItem> imports;

	void load(BinaryReader &reader);
	void save();

	void load_dir_file(BinaryReader &reader);
	void save_dir_file();

	void poplate_uncategorized();

	void remove_file(const fs::path& file) const;
	void import_file(const fs::path& path, const fs::path& file) const;
	void export_file(const fs::path& path, const fs::path& file) const;
	int file_size(const fs::path& file) const;
};
