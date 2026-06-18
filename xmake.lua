set_project("aoc-2025")
set_version("1.0.0")

set_languages("c11")
add_rules("mode.debug", "mode.release")

-- Warning flags
set_warnings("all", "extra")

-- Build output directory
set_targetdir("build")

-- Common library
target("aoclib")
	set_kind("static")
	add_files("lib/aoc.c")
	add_includedirs("lib", {public = true})

-- Helper function to add a day target
function add_day(day)
	local name = string.format("day%02d", day)
	target(name)
		set_kind("binary")
		add_files(name .. "/main.c")
		add_deps("aoclib")
		set_rundir("$(projectdir)/" .. name)
end

-- Add all days
for i = 1, 25 do
	add_day(i)
end
