# Patrick's prelab

## CombineFiles.sh

```bash
#!/bin/bash
file1=$(<$2)
file2=$(<$3)
echo $file1 > $1
echo $file2 >> $1
```

## wc2.sh

```bash
#!/bin/bash
./CombineFiles.sh wc2_output.txt $2 $1
wc wc2_output.txt
```