from folder.subfolder import filename
from folder.subfolder.filename import ClassName as Cn, function_name as fn

cls = filename.ClassName()
print(filename.function_name())
print(cls.method_name())

cls = Cn()
print(fn())
print(cls.method_name())

############################################3

# from one import one
# import two
#
# print(one.one())
# print(two.two())
