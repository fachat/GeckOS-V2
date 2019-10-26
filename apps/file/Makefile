
files= mkdir rmdir rm chkdsk format ls cat mv

all: ${files}

${files}: %: %.a65
	xa -I../../include -R -LLIB6502 $@.a65 -o $@

clean:
	rm -f ${files}

rmdir.a65: mkdir.a65
	cat mkdir.a65 | sed -e "s/mkdir/rmdir/g" -e "s/FC_MKDIR/FC_RMDIR/g" > rmdir.a65

rm.a65: mkdir.a65
	cat mkdir.a65 | sed -e "s/mkdir/rm/g" -e "s/FC_MKDIR/FC_DELETE/g" > rm.a65

chkdsk.a65: mkdir.a65
	cat mkdir.a65 | sed -e "s/mkdir/chkdsk/g" -e "s/FC_MKDIR/FC_CHKDSK/g" > chkdsk.a65

format.a65: mkdir.a65
	cat mkdir.a65 | sed -e "s/mkdir/format/g" -e "s/FC_MKDIR/FC_FORMAT/g" > format.a65

