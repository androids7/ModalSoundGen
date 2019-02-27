rm -rf data
dir=ready
mkdir data
csv=list.csv
for subdir in $(ls $dir)
do
	if [ $subdir -le 100 ]
	then
		echo $subdir
		output=data/$subdir
		mkdir $output
		for mat in $(ls $dir/$subdir | grep "mat-")
		do
			matdir=$output/$mat
			mkdir $matdir
			cp ${dir}/${subdir}/$mat/obj-* $matdir
			cfg=$matdir/config.ini
			touch $cfg
			matname=$(echo $mat | cut -d - -f2)
			matcfg=material/material-${matname}.cfg
			name=$(ls $matdir | grep .obj | cut -d . -f1)
			echo "[mesh]" >> $cfg
		        echo "surface_mesh = ${name}.obj" >> $cfg
		        echo "[modal]" >> $cfg
		        cat $matcfg | grep -E "density|alpha|beta" >> $cfg
		        echo "shape = ${name}.ev" >> $cfg
		        echo "vtx_map = ${name}.vmap" >> $cfg
		        echo "[output]" >> $cfg
		        echo "name = ${matdir}" >> $cfg
			mkdir $matdir/out
			click_synth $cfg
			voxelizer $matdir/${name}.obj $matdir/${name}
			echo "$matdir/${name},$matcfg,$matdir/out" >> $csv
		done

	fi
	


done 
