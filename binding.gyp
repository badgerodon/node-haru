{
	"targets": [
		{
			"target_name": "haru",
			"sources": [
				"src/page.cc",
				"src/page_sizes.cc",
				"src/font.cc",
				"src/init.cc",
				"src/doc.cc",
				"src/page_direction.cc",
				"src/text_alignment.cc"
			],
			"link_settings": {
				"libraries": [
					"-lhpdf"
				]
			},
			"cflags": [
				"-I../include",
				"-O3",
				"-Wall",
				"-D_FILE_OFFSET_BITS=64",
				"-D_LARGEFILE_SOURCE"
			]
		}
	]
}