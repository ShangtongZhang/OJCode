class File(object):
    def __init__(self, name):
        self.name = name
        self.content = ""

class Dir(object):
    def __init__(self, name):
        self.name = name
        self.content = dict()

class FileSystem(object):
    def __init__(self):
        self.disk = Dir('/')

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        if path == '/':
            dirs = []
        else:
            dirs = path.split('/')[1:]
        cur_dir = self.disk
        for dir_name in dirs:
            if dir_name not in cur_dir.content.keys():
                cur_dir.content[dir_name] = Dir(dir_name)
            cur_dir = cur_dir.content[dir_name]
        if isinstance(cur_dir, File):
            return [cur_dir.name]
        res = []
        for name in cur_dir.content.keys():
            res.append(name)
        return sorted(res)

    def mkdir(self, path):
        """
        :type path: str
        :rtype: void
        """
        dirs = path.split('/')[1:]
        cur_dir = self.disk
        for dir_name in dirs:
            if dir_name not in cur_dir.content.keys():
                cur_dir.content[dir_name] = Dir(dir_name)
            cur_dir = cur_dir.content[dir_name]

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: void
        """
        names = filePath.split('/')[1:]
        cur_dir = self.disk
        for dir_name in names[:-1]:
            if dir_name not in cur_dir.content.keys():
                cur_dir.content[dir_name] = Dir(dir_name)
            cur_dir = cur_dir.content[dir_name]
        file_name = names[-1]
        if file_name not in cur_dir.content.keys():
            cur_dir.content[file_name] = File(file_name)
        cur_dir.content[file_name].content += content


    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        names = filePath.split('/')[1:]
        cur_dir = self.disk
        for dir_name in names[:-1]:
            if dir_name not in cur_dir.content.keys():
                cur_dir.content[dir_name] = Dir(dir_name)
            cur_dir = cur_dir.content[dir_name]
        file_name = names[-1]
        if file_name not in cur_dir.content.keys():
            return ''
        return cur_dir.content[file_name].content

obj = FileSystem()
print obj.ls('/')
obj.mkdir('/a/b/c')
obj.addContentToFile('/a/b/c/d', 'hello')
print obj.ls('/')
print obj.readContentFromFile('/a/b/c/d')


