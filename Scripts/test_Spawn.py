import mq2

me = mq2.Character();

print 'Testing Spawn Type\r\n'
print 'Name Related Properties\r\n'
print "%s\t%s" % ('Name', me.Name)
print "%s\t%s" % ('Surname', me.Surname)
print "%s\t%s" % ('CleanName', me.CleanName)
print "%s\t%s" % ('DisplayName', me.DisplayName)
print "%s\t%s" % ('Title', me.Title)
print "%s\t%s" % ('Suffix', me.Suffix)
print '\r\nGeneral Properties\r\n'
print "%s\t%i" % ('Level', me.Level)
print "%s\t%i" % ('ID', me.ID)
print "%s\t%i" % ('CurrentHPs', me.CurrentHPs)
print "%s\t%i" % ('MaxHPs', me.MaxHPs)
print "%s\t%.2f" % ('PctHPs', me.PctHPs)
print "%s\t%i" % ('AARank', me.AARank)
print "%s\t%.2f" % ('Speed', me.Speed)
print 'Testing Header Type'
print "\t%s\t%i" % ('Heading.Clock', me.Heading.Clock)
print "\t%s\t%.2f" % ('Heading.Degrees', me.Heading.Degrees)
print "\t%s\t%.2f" % ('Heading.DegreesCCW', me.Heading.DegreesCCW)
print "\t%s\t%s" % ('Heading.ShortName', me.Heading.ShortName)
print "\t%s\t%s" % ('Heading.Name', me.Heading.Name)
print "%s\t%s" % ('Gender', me.Gender)
print 'Testing Race Type'
print "\t%s\t%i" % ('Race.ID', me.Race.ID)
print "\t%s\t%s" % ('Race.Name', me.Race.Name)
print "%s\t%s" % ('Type', me.Type.value)
print "%s\t%s" % ('Class', me.Class.value)
