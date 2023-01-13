add_rules("mode.debug", "mode.release")

target("atm_controller")
    set_kind("shared")
    add_includedirs("src/include")
    add_files("src/*.c")

target("test")
    set_kind("binary")
    add_deps("atm_controller")
    add_includedirs("src/include")
    add_files("test/runner.c")
    add_files("test/api/*.c")

