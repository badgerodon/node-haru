srcdir = "."
blddir = "build"
VERSION = "0.0.1"

def set_options(opt):
  opt.tool_options("compiler_cxx")

def configure(conf):
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")
  conf.check(lib='hpdf', uselib_store='HPDF', mandatory=True)

def build(bld):
  bld.env.append_value('LINKFLAGS', '-lhpdf')
  obj = bld.new_task_gen("cxx", "shlib", "node_addon")
  obj.cxxflags = [
    "-O3",
    "-Wall",
    "-D_FILE_OFFSET_BITS=64",
    "-D_LARGEFILE_SOURCE"
  ]
  obj.target = "haru"
  obj.source = bld.glob('src/*.cc')
  obj.uselib = ['HPDF','PNG','ZLIB']