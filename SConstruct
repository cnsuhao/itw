#--*-- python --*--
import sys, os, os.path, platform, re, shutil
env = Environment()
env['TOP_DIR'] = env.Dir('#').abspath

# debug = 1
DEBUG_FLAG = ARGUMENTS.get('debug', 0)

if int(DEBUG_FLAG) :
	cc_flags = {'CCFLAGS' : [
	'-g',
	'-pthread',
	'-DNDEBUG']}
else :
	cc_flags = {'CCFLAGS' : [
	'-g',
	'-pthread']}

env.MergeFlags(cc_flags)

Export('env')
#Execute(Delete('./target'))

env.SConscript([
	'src/itwserver/SConscript'
	])




